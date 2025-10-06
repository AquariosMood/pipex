/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:42:16 by crios             #+#    #+#             */
/*   Updated: 2024/11/01 15:46:49 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*my_getenv(char *name, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0
			&& envp[i][ft_strlen(name)] == '=')
			return (envp[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}

static char	*build_full_path(char *dir, char *cmd)
{
	char	*temp_path;
	char	*full_path;

	temp_path = ft_strjoin(dir, "/");
	if (!temp_path)
		return (NULL);
	full_path = ft_strjoin(temp_path, cmd);
	free(temp_path);
	return (full_path);
}

char	*find_executable_path(char *cmd, char **paths)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = build_full_path(paths[i], cmd);
		if (!full_path)
			return (NULL);
		if ((access(full_path, F_OK | X_OK) == 0))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path_env;
	char	*full_path;

	path_env = my_getenv("PATH", envp);
	if (!path_env)
		return (cmd);
	all_paths = ft_split(path_env, ':');
	full_path = find_executable_path(cmd, all_paths);
	ft_free_tab(all_paths);
	if (full_path)
		return (full_path);
	return (cmd);
}

void	setup_file_descriptors(char *file, int fd_to_dup, int flags)
{
	int	new_fd;

	new_fd = open(file, flags | O_CREAT, 0644);
	if (new_fd < 0)
	{
		perror("Error opening file");
		exit_handler(1);
	}
	dup2(new_fd, fd_to_dup);
	close(new_fd);
}
