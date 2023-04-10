/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:53:23 by noloupe           #+#    #+#             */
/*   Updated: 2023/04/10 15:43:00 by noloupe          ###   ########.fr       */
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

# define RD 0
# define WRCRTR 1
# define WRCRAP 2
# define HEREDOC 0
# define BASIC 1

typedef struct s_data
{
	int	i;
	int	j;
	int	fd1;
	int	fd2;
	int	*pids;
}	t_data;

void	free_tab(char **tab);
char	*get_path(char *cmd, char **envp);
void	commands(char *argv, char **envp);
int		get_fd(char	*argv, int type);
void	here_doc(int argc, char *LIM, t_data *data);
void	make_child(char *argv, char **envp, t_data *data);
void	lim_check(int fd, char *LIM);
void	forker(int argc, char **argv, char **envp, t_data *data);
void	set_struct(char **argv, int argc, t_data *data, int type);
void	waitpids(t_data *data);

/* ERRORS */

void	args_error(void);
void	print_perror(char *str);

#endif