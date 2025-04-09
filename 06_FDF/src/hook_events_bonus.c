/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:20:49 by layang            #+#    #+#             */
/*   Updated: 2025/03/10 10:19:06 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	key_hooks_2(int keycode, t_vars	*all)
{
	if (keycode == XK_y)
		rotate_y(all->map, -0.1);
	if (keycode == XK_h)
		rotate_y(all->map, 0.1);
	if (keycode == XK_z)
		scale_z(all, 1.1);
	if (keycode == XK_a)
		scale_z(all, 1 / 1.1);
	if (keycode == XK_t)
	{
		reset_map(all);
		autoscale(all->map);
	}
	if (keycode == XK_r)
	{
		reset_map(all);
		projection_scale_07(all->map);
		autoscale(all->map);
	}
	if (keycode == XK_space)
		all->animate ^= 0x1;
	return (0);
}

static int	key_hooks(int keycode, t_vars	*all)
{
	if (keycode == XK_Escape)
		close_fdf(all);
	if (keycode == XK_equal)
		zoom(all->map, 1.2);
	if (keycode == XK_minus)
		zoom(all->map, 1 / 1.2);
	if (keycode == XK_Left)
		translate(all->map, (t_point){-10, 0, 0, 0});
	if (keycode == XK_Right)
		translate(all->map, (t_point){10, 0, 0, 0});
	if (keycode == XK_Up)
		translate(all->map, (t_point){0, -10, 0, 0});
	if (keycode == XK_Down)
		translate(all->map, (t_point){0, 10, 0, 0});
	if (keycode == XK_x)
		rotate_x(all->map, -0.1);
	if (keycode == XK_s)
		rotate_x(all->map, 0.1);
	else
		key_hooks_2(keycode, all);
	return (0);
}

void	hook_control_bonus(t_vars	*all)
{
	mlx_hook(all->win, DestroyNotify, 0, close_fdf, all);
	mlx_key_hook(all->win, key_hooks, all);
}

void	render_instructions(t_vars	*all)
{
	mlx_string_put(all->mlx, all->win, 30, 30,
		WHITE, "Zoom: Keypad +, -");
	mlx_string_put(all->mlx, all->win, 30, 50,
		WHITE, "Translate: Up, Down, Left, Right");
	mlx_string_put(all->mlx, all->win, 30, 70,
		WHITE, "Rotate: x, s, y, h");
	mlx_string_put(all->mlx, all->win, 30, 90,
		WHITE, "Change Height: z, a");
	mlx_string_put(all->mlx, all->win, 30, 110,
		WHITE, "Reset Isometric View: r");
	mlx_string_put(all->mlx, all->win, 30, 130,
		WHITE, "Top View: t");
	mlx_string_put(all->mlx, all->win, 30, 150,
		WHITE, "Animate: Space");
}
