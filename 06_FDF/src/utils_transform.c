/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:41:04 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:16:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*fdf_transform(t_map	*map, t_mat	rot_mat)
{
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = multi_mat(rot_mat, *cur);
		i++;
	}
	map->i = multi_mat(rot_mat, map->i);
	map->j = multi_mat(rot_mat, map->j);
	map->k = multi_mat(rot_mat, map->k);
	return (map);
}

void	reset_map(t_vars	*all)
{
	int	i;

	i = 0;
	while (i < all->map->dim_x * all->map->dim_y)
	{
		*(all->map->grid + i) = *(all->orig_map->grid + i);
		i++;
	}
	all->map->i = (t_point){1, 0, 0, 0x0};
	all->map->j = (t_point){0, 1, 0, 0x0};
	all->map->k = (t_point){0, 0, 1, 0x0};
}

void	re_translate(t_map	*map)
{
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = vec_add(*cur, map->locate);
		i++;
	}
}

void	autoscale(t_map	*map)
{
	float_t	scale_x;
	float_t	scale_y;
	t_point	*cur;
	int		i;
	int		range[4];

	ft_memset(range, 0, sizeof(range));
	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if (cur->x < range[0])
			range[0] = cur->x;
		if (cur->x > range[1])
			range[1] = cur->x;
		if (cur->y < range[2])
			range[2] = cur->y;
		if (cur->y > range[3])
			range[3] = cur->y;
		i++;
	}
	scale_x = (WIDTH / 2 - 150) / fmaxf(abs(range[1]), abs(range[0]));
	scale_y = (HEIGHT / 2 - 150) / fmaxf(abs(range[3]), abs(range[2]));
	zoom(map, fminf(scale_x, scale_y));
}

void	zoom(t_map	*map, float_t factor)
{
	t_mat	scale;

	scale = (t_mat){factor, 0, 0, 0, factor, 0, 0, 0, factor};
	fdf_transform(map, scale);
}
