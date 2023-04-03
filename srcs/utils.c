/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:38:55 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/30 11:35:47 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	get_fd(char *argv, int type)
{
	int	fd;

	fd = 0;
	if (type == 0)
		fd = open(argv, O_RDONLY);
	else if (type == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		print_perror("fd");
	return (fd);
}
