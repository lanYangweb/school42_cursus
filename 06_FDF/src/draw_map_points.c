/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:51 by layang            #+#    #+#             */
/*   Updated: 2025/03/10 11:03:10 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	renew_range_z_04(t_map	*map, t_point	*cur)
{
	if (cur->z < map->min_z)
		map->min_z = cur->z;
	if (cur->z > map->max_z)
		map->max_z = cur->z;
}

static void	fill_row_03(t_map	*map, char	**row, int	*j)
{
	t_point	*cur;
	t_point	p;
	int		col;

	p.x = -map->cell_size * map->dim_x / 2;
	p.y = -map->cell_size * map->dim_y / 2 + map->cell_size * (*j);
	if (*j == 0 && ft_strchr(*row, ','))
		map->with_color = 1;
	col = 0;
	while (col < map->dim_x)
	{
		cur = map->grid + col + map->dim_x * (*j);
		*cur = p;
		cur->z = ft_atoi(row[col]);
		renew_range_z_04(map, cur);
		if (map->with_color == 1)
			cur->color = ft_atoi_base((ft_strchr(row[col], 'x')
						+ 1), "0123456789abcdef");
		else
			cur->color = GROUND_COLOR;
		p.x += map->cell_size;
		col++;
	}
	(*j)++;
}

t_map	*fill_map_02(t_vars	*all, char	*file)
{
	int		fd;
	char	*line;
	char	**row;
	t_map	*map;
	int		j;

	fd = open(file, O_RDONLY);
	map = all->map;
	map->cell_size = 10;
	map->grid = malloc(map->dim_x * map->dim_y * sizeof(t_point));
	if (map->grid == NULL)
		return (NULL);
	j = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		row = ft_split(line, ' ');
		fill_row_03(map, row, &j);
		ft_free_array(row);
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (map);
}

static void	color_points_06(t_map	*map)
{
	float_t	ratio;
	int		rgb[3];
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if (cur->z > 0)
		{
			ratio = cur->z / map->max_z;
			gradient_color(ratio, rgb, GROUND_COLOR, HIGH_COLOR);
			cur->color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		}
		if (cur->z < 0)
		{
			ratio = (map->min_z - cur->z) / map->min_z;
			gradient_color(ratio, rgb, LOW_COLOR, GROUND_COLOR);
			cur->color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		}
		i++;
	}
	change_42fdf_color(map);
}

int	color_and_save_05(t_vars	*all)
{
	int		i;
	t_point	*cur;

	if (all->map->max_z != 0 && all->map->with_color == 0)
		color_points_06(all->map);
	all->orig_map = malloc(sizeof(t_map));
	if (all->orig_map == NULL)
		return (ft_putstr_fd("FDF: create orig_map failed.\n", 2), -1);
	all->orig_map->grid = malloc(all->map->dim_x
			* all->map->dim_y * sizeof(t_point));
	if (all->orig_map->grid == NULL)
		return (ft_putstr_fd("FDF: create grid failed.\n", 2), -1);
	i = 0;
	while (i < all->map->dim_x * all->map->dim_y)
	{
		cur = all->map->grid + i;
		*(all->orig_map->grid + i) = *cur;
		i++;
	}
	all->map->i = (t_point){1, 0, 0, 0x0};
	all->map->j = (t_point){0, 1, 0, 0x0};
	all->map->k = (t_point){0, 0, 1, 0x0};
	return (0);
}
