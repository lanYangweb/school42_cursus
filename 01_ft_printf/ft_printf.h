/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:25 by layang            #+#    #+#             */
/*   Updated: 2024/11/18 13:28:31 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar_n(char c);
int		ft_putstr_n(char	*s);
int		ft_put_n(long long nb);
int		ft_put_un(long long nb);
int		ft_put_h(unsigned long nb, char *base);
int		ft_put_ptr(void	*ptr_hex);
// function principal
int		ft_printf(const char *format, ...);

#endif