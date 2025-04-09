/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:57:54 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:19:04 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* void projection_scale_07(t_map *map)
{	
	t_mat	iso;

	iso = (t_mat){cos(M_PI / 6), -cos(M_PI / 6), 0,
    sin(M_PI / 6), sin(M_PI / 6), -1,
    0, 0, 1};
	fdf_transform(map, iso);
	autoscale(map);
} */

void	projection_scale_07(t_map	*map)
{
	rotate_x(map, -M_PI_2);
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO_RADIAN);
	autoscale(map);
}

void	render_background(t_pic	*img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(img, (t_point){j, i, 0, color});
			j++;
		}
		i++;
	}
}

void	map_to_img(t_pic	*img, t_map	*map, t_point	offset)
{
	int		i;
	t_point	*cur;
	t_point	point;
	t_point	point_right;
	t_point	point_down;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		point = vec_add(*cur, offset);
		if (i % map->dim_x != map->dim_x - 1)
		{
			point_right = vec_add(*(cur + 1), offset);
			draw_bresenham_line(img, point, point_right);
		}
		if (i < map->dim_x * map->dim_y - map->dim_x)
		{
			point_down = vec_add(*(cur + map->dim_x), offset);
			draw_bresenham_line(img, point, point_down);
		}
		i++;
	}
}
