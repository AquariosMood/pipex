/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:02:37 by crios             #+#    #+#             */
/*   Updated: 2024/10/31 14:28:03 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_user_input(int pipe_fd[2], char *limiter)
{
	char	*buffer;
	int		bytes_read;

	close(pipe_fd[0]);
	buffer = malloc(ft_strlen(limiter) + 2);
	if (!buffer)
		exit_handler(1);
	while (1)
	{
		write(1, "> ", 2);
		bytes_read = read(STDIN_FILENO, buffer, ft_strlen(limiter) + 1);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0
			&& buffer[ft_strlen(limiter)] == '\n')
			break ;
		write(pipe_fd[1], buffer, bytes_read);
	}
	free(buffer);
	close(pipe_fd[1]);
}

void	handle_heredoc(char *limiter)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		exit_handler(2);
	pid = fork();
	if (pid == 0)
	{
		handle_user_input(pipe_fd, limiter);
		exit(0);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	waitpid(pid, NULL, 0);
}

void	execute_command(char *command, char **envp)
{
	char	**command_args;
	pid_t	pid;

	command_args = ft_split(command, ' ');
	if (!command_args)
		exit_handler(1);
	pid = fork();
	if (pid == 0)
	{
		execve(get_path(command_args[0], envp), command_args, envp);
		perror("pipex");
		ft_free_tab(command_args);
		exit(127);
	}
	else if (pid < 0)
	{
		perror("fork");
		ft_free_tab(command_args);
		exit(1);
	}
	ft_free_tab(command_args);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	is_heredoc;

	is_heredoc = ft_strncmp(argv[1], "here_doc", 8) == 0;
	if (argc < 5)
		exit_handler(1);
	if (is_heredoc)
		handle_heredoc(argv[2]);
	else
		setup_file_descriptors(argv[1], STDIN_FILENO, O_RDONLY);
	setup_file_descriptors(argv[argc - 1], STDOUT_FILENO,
		O_WRONLY | O_CREAT | O_TRUNC);
	execute_pipeline(argc, argv, envp, is_heredoc);
	return (0);
}
