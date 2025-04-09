/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:33:13 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:21:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	gradient_color(float_t	r, int rgb[3], int s, int e)
{
	rgb[0] = (int)roundf((1 - r) * ((s >> 16) & 0xFF) + r * ((e >> 16) & 0xFF));
	rgb[1] = (int)roundf((1 - r) * ((s >> 8) & 0xFF) + r * ((e >> 8) & 0xFF));
	rgb[2] = (int)roundf((1 - r) * (s & 0xFF) + r * (e & 0xFF));
}

int	get_pix_color(t_point	cur, t_point start, t_point end)
{
	t_point	delta;
	float_t	ratio;
	int		rgb[3];
	int		len;
	int		pos;

	if (cur.color == end.color)
		return (cur.color);
	delta = vec_sub(end, start);
	len = sqrt(delta.x * delta.x + delta.y * delta.y);
	if (len == 0)
		return (start.color);
	delta = vec_sub(cur, start);
	pos = sqrt(delta.x * delta.x + delta.y * delta.y);
	ratio = (float_t)pos / (float_t)len;
	gradient_color(ratio, rgb, start.color, end.color);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	change_42fdf_color(t_map	*map)
{
	int		i;
	t_point	*cur;

	if (!map->fdf42)
		return ;
	i = -1;
	while (++i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if ((i % map->dim_x != map->dim_x - 1)
			&& (i < map->dim_x * map->dim_y - map->dim_x)
			&& (cur->color != (cur + 1)->color
				|| cur->color != (cur + map->dim_x)->color))
		{
			if (cur->z != map->max_z)
				cur->color = YELLOW;
			if (cur->z == map->max_z && cur->color != (cur + 1)->color)
				(cur + 1)->color = YELLOW;
			if (cur->z == map->max_z
				&& cur->color != (cur + map->dim_x)->color)
				(cur + map->dim_x)->color = YELLOW;
		}
		i++;
	}
}
