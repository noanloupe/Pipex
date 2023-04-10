/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:38:55 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/10 15:43:48 by noloupe          ###   ########.fr       */
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
	if (type == RD)
		fd = open(argv, O_RDONLY);
	else if (type == WRCRTR)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == WRCRAP)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		print_perror("fd");
	return (fd);
}

void	set_struct(char **argv, int argc, t_data *data, int type)
{
	if (type == HEREDOC)
	{
		data->i = 3;
		data->j = 0;
		data->fd1 = 0;
		data->fd2 = get_fd(argv[argc - 1], WRCRAP);
		data->pids = malloc(sizeof(int) * argc - 4);
		if (!data->pids)
			print_perror("");
	}
	else if (type == BASIC)
	{
		data->i = 2;
		data->j = 0;
		data->fd1 = get_fd(argv[1], RD);
		data->fd2 = get_fd(argv[argc - 1], WRCRTR);
		data->pids = malloc(sizeof(int) * argc - 3);
		if (!data->pids)
			print_perror("");
	}
}

void	waitpids(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->j)
	{
		waitpid(data->pids[i], NULL, 0);
		i++;
	}
}
