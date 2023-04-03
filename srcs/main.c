/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:15:48 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/03 15:11:33 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.fd1 = 0;
	data.fd2 = 0;
	if (argc < 4)
		args_error();
	if (!ft_memcmp(argv[1], "here_doc", 9))
	{
		data.i = 2;
		data.fd2 = get_fd(argv[argc - 1], 1);
		here_doc(argc, argv[2]);
	}
	else
	{
		data.i = 1;
		data.fd1 = get_fd(argv[1], 0);
		data.fd2 = get_fd(argv[argc - 1], 1);
		if (dup2(data.fd1, STDIN_FILENO) == -1)
			print_perror("dup2");
	}
	forker(argc, argv, envp, data);
	return (0);
}

void	forker(int argc, char **argv, char **envp, t_data data)
{
	int	pid;

	while (++data.i < argc - 2)
		make_child(argv[data.i], envp);
	if (dup2(data.fd2, STDOUT_FILENO) == -1)
		print_perror("dup2");
	pid = fork();
	if (pid == -1)
		print_perror("pid");
	if (pid == 0)
		commands(argv[argc - 2], envp);
	waitpid(pid, NULL, 0);
	if (data.fd1 != 0)
		close(data.fd1);
	close(data.fd2);
}
