/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:43 by crios             #+#    #+#             */
/*   Updated: 2024/10/07 15:21:37 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler(1);
	if (pipe(pipe_fd) == -1)
		exit_handler(2);
	pid = fork();
	if (pid == -1)
		exit_handler(3);
	if (pid == 0)
		child_process(argv, pipe_fd, envp);
	else
		parent_process(argv, pipe_fd, envp);
	return (0);
}
