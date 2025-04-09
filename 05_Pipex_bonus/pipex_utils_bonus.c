/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:06:03 by layang            #+#    #+#             */
/*   Updated: 2025/02/14 16:08:13 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(char **av, int ac)
{
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	open_mode(char	*file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		if (mode == 2)
			error(1);
		if (mode == 0 && access(file, F_OK) == 0
			&& access(file, R_OK) == -1)
			fd = open("/dev/null", O_RDONLY);
		else
			error(3);
	}
	return (fd);
}
