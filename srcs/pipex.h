/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:53:23 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/03 15:11:43 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	int	i;
	int	fd1;
	int	fd2;
}	t_data;

void	free_tab(char **tab);
char	*get_path(char *cmd, char **envp);
void	commands(char *argv, char **envp);
int		get_fd(char	*argv, int type);
void	here_doc(int argc, char *LIM);
void	make_child(char *argv, char **envp);
void	lim_check(int fd, char *LIM);
void	forker(int argc, char **argv, char **envp, t_data data);

/* ERRORS */

void	args_error(void);
void	print_perror(char *str);

#endif