/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:47:45 by crios             #+#    #+#             */
/*   Updated: 2024/11/01 15:20:38 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(char **argv, int *pipe_fd, char **envp)
{
	int		input_fd;
	char	**cmd_args;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 0)
	{
		perror("Error opening input file");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit_handler(1);
	}
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(input_fd);
	cmd_args = ft_split(argv[2], ' ');
	if (execve(get_path(cmd_args[0], envp), cmd_args, envp) == -1)
	{
		ft_printf("Error: Command '%s' not found\n", cmd_args[0]);
		ft_free_tab(cmd_args);
		close(pipe_fd[1]);
		exit_handler(1);
	}
}

void	parent_process(char **argv, int *pipe_fd, char **envp)
{
	int		output_fd;
	char	**cmd_args;

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		perror("Error opening output file");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit_handler(1);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(output_fd);
	cmd_args = ft_split(argv[3], ' ');
	if (execve(get_path(cmd_args[0], envp), cmd_args, envp) == -1)
	{
		ft_printf("Error: Command '%s' not found\n", cmd_args[0]);
		ft_free_tab(cmd_args);
		close(pipe_fd[0]);
		exit_handler(1);
	}
}
