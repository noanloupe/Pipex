/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:51:39 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/03 14:39:46 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_child(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		print_perror("pipe");
	pid = fork();
	if (pid == -1)
		print_perror("pid");
	if (pid == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			print_perror("dup2");
		close(fd[0]);
		close(fd[1]);
		commands(argv, envp);
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			print_perror("dup2");
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(int argc, char *LIM)
{
	int		fd[2];
	pid_t	pid;

	if (argc < 5)
		args_error();
	if (pipe(fd) == -1)
		print_perror("pipe");
	pid = fork();
	if (pid == -1)
		print_perror("dup2");
	else if (pid == 0)
	{
		close(fd[0]);
		while (1)
			lim_check(fd[1], LIM);
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			print_perror("dup2");
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	lim_check(int fd, char *LIM)
{
	char	*line;

	line = get_next_line(0);
	if (!ft_memcmp(line, LIM, ft_strlen(LIM)))
	{
		close(fd);
		free(line);
		exit(EXIT_SUCCESS);
	}
	write(fd, line, ft_strlen(line));
	free(line);
}
