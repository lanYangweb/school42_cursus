/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:53:22 by layang            #+#    #+#             */
/*   Updated: 2024/12/02 11:32:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*src);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strchr(const char	*s, int c);

char	*get_next_line(int fd);

#endif
