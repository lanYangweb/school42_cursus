/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:05:33 by layang            #+#    #+#             */
/*   Updated: 2025/02/21 15:29:39 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* static void	input_here_doc(char *limiter, int *pipe_fd)
{
	char	*line;
	char	*compare;
	size_t	len;

	close(pipe_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		compare = ft_strdup(line);
		len = ft_strlen(compare);
		if (len > 0 && compare[len - 1] == '\n')
			compare[len - 1] = '\0';
		if (ft_strncmp(compare, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(compare);
			free(line);
			get_next_line(-1);
			exit(0);
		}
		ft_putstr_fd(line, pipe_fd[1]);
		free(line);
		free(compare);
	}
} */

// here_doc use no ft_strdup (get next line = str + '\n' + '\0', 
// while limiter = str + '\0')

static void	input_here_doc(char *limiter, int *pipe_fd)
{
	char	*line;
	size_t	len;

	close(pipe_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		len = ft_strlen(limiter);
		if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
		{
			free(line);
			get_next_line(-1);
			exit(0);
		}
		ft_putstr_fd(line, pipe_fd[1]);
		free(line);
	}
}

static void	do_here_doc(char	*limiter)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
		input_here_doc(limiter, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		wait(NULL);
	}
}

static void	do_multi_pipe(char *cmd, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execute(cmd, env);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		if (ft_strncmp(cmd, "sleep", 5) == 0)
			waitpid(pid, NULL, 0);
	}
}

static void	do_pipex_bonus(int ac, char **av, char **env)
{
	int	i;
	int	input;
	int	output;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		output = open_mode(av[5], 2);
		do_here_doc(av[2]);
	}
	else
	{
		i = 2;
		input = open_mode(av[1], 0);
		output = open_mode(av[ac - 1], 1);
		dup2(input, 0);
	}
	while (i < ac - 2)
		do_multi_pipe(av[i++], env);
	if (dup2(output, 1) == -1)
		exit(1);
	execute(av[ac - 2], env);
}

/* static void do_pipex_bonus(int ac, char **av, char **env)
{
	int i;
	int input;
	int output;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		output = open_mode(av[ac - 1], 2);
		if (output == -1) // 检测输出文件是否无法打开
		{
			perror("pipex: cannot write to output file");
			exit(1);
		}
		do_here_doc(av[2]);
	}
	else
	{
		i = 2;
		input = open_mode(av[1], 0);
		output = open_mode(av[ac - 1], 1);
		if (input == -1) // 检测输入文件是否无法打开
		{
			perror("pipex: cannot open input file");
			exit(1);
		}
		if (output == -1) // 检测输出文件是否无法打开
		{
			perror("pipex: cannot write to output file");
			exit(1);
		}
		dup2(input, 0);
		close(input);
	}
	while (i < ac - 2)
		do_multi_pipe(av[i++], env);
	if (dup2(output, 1) == -1)
	{
		perror("pipex: dup2 failed");
		close(output);
		exit(1);
	}
	close(output);
	execute(av[ac - 2], env);
} */

int	main(int ac, char **av, char **env)
{
	if (ac >= 5 && check_args(av, ac))
		do_pipex_bonus(ac, av, env);
	error(0);
}

// ./pipex "42_pipex_tester/infiles/basic.txt" "cat" "head -2" "outfiles"
// ./pipex "42_pipex_tester/infiles/big_text.txt" "cat" "head -2" "outfiles" 
// ./pipex "nonexistingfile" "cat -e" "ls" "outfiles"  
// ./pipex "nonexistingfile" "cat" "sleep 3" "outfiles"
// ./pipex "42_pipex_tester/infiles/infile_without_permissions" 
// "cat -e" "cat -e" "outfiles"