/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:47:50 by layang            #+#    #+#             */
/*   Updated: 2025/03/10 11:17:39 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_fdf(t_vars	*all)
{
	mlx_destroy_window(all->mlx, all->win);
	all->win = NULL;
	mlx_destroy_image(all->mlx, all->img.mlx_img);
	mlx_destroy_display(all->mlx);
	free(all->map->grid);
	free(all->map);
	free(all->orig_map->grid);
	free(all->orig_map);
	free(all->mlx);
	exit(0);
	return (0);
}

/* void	free_fdf(int flag, ...)
{
	va_list	a_list;
	void	*ptr;

	va_start(a_list, flag);
	if (flag == -1)
		get_next_line(-1, 0);
	while ((ptr = va_arg(a_list, void *)) != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	va_end(a_list);
} */

void	free_fdf(int flag, ...)
{
	va_list	a_list;
	void	*ptr;

	va_start(a_list, flag);
	if (flag == -1)
		get_next_line(-1, 0);
	ptr = va_arg(a_list, void *);
	while (ptr != NULL)
	{
		free(ptr);
		ptr = va_arg(a_list, void *);
	}
	va_end(a_list);
}

/* t_win_list				*new_win
t_img	*img
t_xvar	*xvar
free(all->map), free(line), get_next_line(-1, 0) */

/* typedef enum e_type
{
    TYPE_T_MAP,
    TYPE_INT,
    TYPE_STRING,
    // 添加更多类型
} t_type;

void free_fdf(int flag, ...)
{
    va_list args;
    void *ptr;
    t_type type;

    va_start(args, flag);
    while ((ptr = va_arg(args, void *)) != NULL)
    {
        type = va_arg(args, t_type);  // 获取类型标识符
        switch (type)
        {
            case TYPE_T_MAP:
                free_map((t_map *)ptr);
                break;
            // 其他类型的处理
            default:
                break;
        }
    }
    va_end(args);
} */

static int	key_hooks_esc(int keycode, t_vars	*all)
{
	if (keycode == XK_Escape)
		close_fdf(all);
	return (0);
}

void	hook_control(t_vars	*all)
{
	mlx_hook(all->win, DestroyNotify, 0, close_fdf, all);
	mlx_key_hook(all->win, key_hooks_esc, all);
}
