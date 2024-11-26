/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:53:22 by layang            #+#    #+#             */
/*   Updated: 2024/11/25 20:03:27 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t	ft_strlen(const char	*str);
void	*ft_memmove(void	*dst, const void	*src, size_t n);
char	*alloc_copy(char	*line, size_t len, char	*buffer, size_t copy_len);
int		find_newline(char	*buffer, size_t bytes_read, size_t *index);

char	*read_and_process(int fd, char	*line, size_t *len);
char	*get_next_line(int fd);

#endif