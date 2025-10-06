/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:44:21 by crios             #+#    #+#             */
/*   Updated: 2024/10/31 14:09:53 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/inc/ft_printf.h"
# include "../lib/inc/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipeline_params
{
	int		*fd_in;
	int		*p_fd;
	char	**argv;
	char	**envp;
	int		cmd_index;
}			t_pipeline_params;

// command
void		child_process(char **argv, int *pipe_fd, char **envp);
void		parent_process(char **argv, int *pipe_fd, char **envp);

// utils
void		exit_handler(int n_exit);
char		*get_path(char *cmd, char **envp);
void		ft_free_tab(char **tab);
void		setup_file_descriptors(char *file, int fd_to_dup, int flags);

// bonus
void		execute_pipeline(int argc, char **argv, char **envp,
				int is_heredoc);
void		execute_command(char *command, char **envp);

#endif
