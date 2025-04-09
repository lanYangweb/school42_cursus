/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:50 by layang            #+#    #+#             */
/*   Updated: 2025/03/31 15:10:35 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int sign)
{
	if (sign == 0)
	{
		ft_putstr_fd("./pipex <file1> cmd1 cmd2 cmd3 cmd4... <file2>\n", 2);
		ft_putstr_fd("or\n", 2);
		ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 <file>\n", 2);
		exit(0);
	}
	perror("pipex");
	if (sign == 1)
		exit(EXIT_FAILURE);
	if (sign == 2)
		exit(0);
}

void	ft_free_array(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

char	*get_path(char	*cmd, char	**env)
{
	char	**paths;
	char	*path_f;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path_f = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_f, cmd);
		free(path_f);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_array(paths);
			return (path);
		}			
		free(path);
	}
	ft_free_array(paths);
	return (NULL);
}

void	execute(char	*cmd, char	**env)
{
	char	*path;
	char	**cmd_line;

	cmd_line = ft_split(cmd, ' ');
	path = get_path(cmd_line[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_line[0], 2);
		ft_free_array(cmd_line);
		exit(127);
	}
	if (execve(path, cmd_line, env) == -1)
	{
		ft_free_array(cmd_line);
		free(path);
		error(1);
	}
}
