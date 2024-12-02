/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:20 by layang            #+#    #+#             */
/*   Updated: 2024/12/02 11:23:16 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static char	*get_line(char	*res)
{
	char	*line;
	int		len;
	int		i;

	if (ft_strchr(res, '\n'))
		len = ft_strchr(res, '\n') - res + 1;
	else
		len = ft_strlen(res);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*res_afterline(char	*res)
{
	char	*for_free;
	char	*new_res;

	for_free = res;
	if (ft_strchr(res, '\n'))
		new_res = ft_strdup(ft_strchr(res, '\n') + 1);
	else
		new_res = ft_strdup("");
	free(for_free);
	for_free = NULL;
	return (new_res);
}

static char	*read_line(int fd, char	*res, char	*buffer)
{
	ssize_t	bytes;
	char	*for_free;
	char	*line;
	
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		for_free = res;
		res = ft_strjoin(for_free, buffer);
		free(for_free);
		for_free = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	line = get_line(res);
	res = res_afterline(res);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	buffer[BUFFER_SIZE];
	char	*res;
	
	line = NULL;
	res = NULL;
	line = read_line(fd, res, buffer);
	if (!line)
		return (NULL);
	return (line);
} */

static char	*get_line(char *res)
{
	char	*line;
	int		len;
	int		i;

	if (ft_strchr(res, '\n'))
		len = ft_strchr(res, '\n') - res + 1;
	else
		len = ft_strlen(res);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*res_afterline(char *res)
{
	char	*new_res;

	if (ft_strchr(res, '\n'))
		new_res = ft_strdup(ft_strchr(res, '\n') + 1);
	else
		new_res = ft_strdup("");
	free(res);
	return (new_res);
}

static char	*read_line(int fd, char **res)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*for_free;

	while (1)
	{
		if (ft_strchr(*res, '\n'))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		for_free = *res;
		*res = ft_strjoin(for_free, buffer);
		free(for_free);
	}
	if (**res == '\0')
		return (NULL);
	return (get_line(*res));
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!res)
		res = ft_strdup("");
	line = read_line(fd, &res);
	if (!line)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	res = res_afterline(res);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	// Check for correct argument count
	if (argc != 2)
	{
		write(2, "Usage: ./a.out <filename>\n", 24);
		return 1;
	}
	// Open the file for reading
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	// Read lines from the file using get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		// Print the line (don't forget to handle newline in the output)
		printf("%s", line);
		free(line);
	}
	// Close the file when done
	close(fd);
	return (0);
}
/* 
cc get_next_line.c get_next_line_utils.c -Wall -Wextra -Werror 
./a.out test.txt 
 */
