/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:25:55 by crios             #+#    #+#             */
/*   Updated: 2024/10/31 11:44:23 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
	{
		ft_printf("%s", "Usage: ./pipex infile cmd1 cmd2 outfile\n");
	}
	if (n_exit == 2)
	{
		ft_printf("%s", "Error: Failed to create pipe\n");
	}
	if (n_exit == 3)
	{
		ft_printf("%s", "Error: Failed to fork process\n");
	}
	exit(n_exit);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
