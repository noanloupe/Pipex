/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:27:23 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/03 14:26:38 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**path_tab;

	i = 0;
	while (envp[i] && ft_memcmp(envp[i], "PATH=", 5))
		i++;
	path_tab = ft_split(envp[i], ':');
	if (!path_tab)
		return (NULL);
	i = -1;
	while (path_tab[++i])
	{
		path = ft_strjoin(path_tab[i], "/");
		path = strjoin_free1(path, cmd);
		if (!access(path, F_OK))
		{
			free_tab(path_tab);
			return (path);
		}
		free(path);
	}
	free_tab(path_tab);
	ft_printf(2, "command not found: %s\n", cmd);
	exit(EXIT_FAILURE);
}

void	commands(char *argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd_args;

	i = 0;
	cmd_args = ft_split(argv, ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	if (!cmd_args[0])
	{
		ft_printf(2, "access denied:\n");
		free_tab(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (!access(cmd_args[0], F_OK))
		execve(cmd_args[0], cmd_args, envp);
	path = get_path(cmd_args[0], envp);
	if (!path)
	{
		ft_printf(2, "split error in get_path\n");
		free_tab(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd_args, envp))
		print_perror("execve");
}
