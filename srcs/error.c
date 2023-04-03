/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:23:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/27 14:55:54 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_error(void)
{
	write(2, "Error: wrong number of arguments\n", 33);
	exit(EXIT_FAILURE);
}

void	print_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
