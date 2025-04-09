/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:24 by layang            #+#    #+#             */
/*   Updated: 2025/02/13 09:49:55 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char	*cmd, char	*file, int *pipe, char	**env)
{
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		error(2);
	dup2(fd, 0);
	dup2(pipe[1], 1);
	close(pipe[0]);
	execute(cmd, env);
}

void	parent(char	*cmd, char	*file, int *pipe, char	**env)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error(1);
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(pipe[1]);
	execute(cmd, env);
}

int	main(int ac, char	**av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("./pipex <file1> cmd1 cmd2 <file2>\n", 2);
		exit(0);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		ft_putstr_fd("command can not be empty\n", 2);
		exit(0);
	}
	if (pipe(pipe_fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
		child(av[2], av[1], pipe_fd, env);
	if (ft_strncmp(av[2], "sleep", 5) == 0)
		waitpid(pid, NULL, 0);
	parent(av[3], av[4], pipe_fd, env);
}
//./pipex infile "ls -l" "wc -l" outfile
// waitpid(pid, NULL, 0);
/* 	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		parent(av[3], av[4], pipe_fd, env);
	waitpid(pid, NULL, 0); */

//waitpid(pid, NULL, 0);