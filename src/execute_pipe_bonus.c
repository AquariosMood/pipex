/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:55:55 by crios             #+#    #+#             */
/*   Updated: 2024/10/31 14:27:44 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child_process(int fd_in, int p_fd[2], char *command, char **envp)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute_command(command, envp);
	exit(0);
}

void	create_pipe_and_fork(int *fd_in, char **argv, char **envp, int *i)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit_handler(2);
	pid = fork();
	if (pid == 0)
		handle_child_process(*fd_in, p_fd, argv[*i], envp);
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	close(p_fd[1]);
	*fd_in = p_fd[0];
	(*i)++;
}

void	execute_pipeline(int argc, char **argv, char **envp, int is_heredoc)
{
	int	i;
	int	fd_in;
	int	fd_out;

	fd_in = STDIN_FILENO;
	if (is_heredoc)
		i = 3;
	else
		i = 2;
	while (i < argc - 1)
	{
		create_pipe_and_fork(&fd_in, argv, envp, &i);
	}
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		exit_handler(1);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	execute_command(argv[argc - 2], envp);
	close(fd_out);
	close(fd_in);
}
