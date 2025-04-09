/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/10 11:11:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdarg.h>

# define WIDTH			1920
# define HEIGHT			1080
# define WHITE			0x00FFFFFF
# define PURPLE			0x009400D3
# define BLUE			0x00000066
# define BLACK			0x00000000
# define YELLOW 		0x00FFB699
# define GROUND_COLOR	WHITE
# define HIGH_COLOR		PURPLE
# define LOW_COLOR		BLUE

# define ISO_RADIAN 	0.6154797

//# define malloc(size) NULL
//# define malloc(size) (size == sizeof(t_map) ? NULL : malloc(size))
//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

typedef struct s_pic
{
	void	*mlx_img;
	void	*addr;
	int		bits_pix;
	int		line_len;
	int		endian;
}	t_pic;

typedef struct s_point
{
	float_t	x;
	float_t	y;
	float_t	z;
	int		color;
}	t_point;

typedef struct s_mat
{
	float_t	x1y1;
	float_t	x2y1;
	float_t	x3y1;
	float_t	x1y2;
	float_t	x2y2;
	float_t	x3y2;
	float_t	x1y3;
	float_t	x2y3;
	float_t	x3y3;
}	t_mat;

typedef struct s_map
{
	t_point	*grid;
	int		cell_size;
	int		dim_x;
	int		dim_y;
	int		max_z;
	int		min_z;
	int		with_color;
	t_point	i;
	t_point	j;
	t_point	k;
	t_point	locate;
	int		fdf42;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_pic	img;
	t_map	*map;
	t_map	*orig_map;
	int		animate;
}	t_vars;

// math tools:
t_point	multi_mat(t_mat	mat, t_point	p);
t_point	vec_add(t_point	p1, t_point	p2);
t_point	vec_sub(t_point	p1, t_point	p2);

// transformation founctions
void	zoom(t_map	*map, float_t	factor);
void	autoscale(t_map	*map);
void	projection_scale_07(t_map	*map);
t_map	*fdf_transform(t_map	*map, t_mat	rot_mat);

// grid and image drawing
t_map	*fill_map_02(t_vars	*all, char	*file);
int		color_and_save_05(t_vars	*all);
void	render_background(t_pic	*img, int color);
void	map_to_img(t_pic	*img, t_map	*map, t_point	offset);
void	gradient_color(float_t	r, int rgb[3], int s, int e);
int		get_pix_color(t_point	cur, t_point	start, t_point	end);
void	put_pixel(t_pic	*img, t_point	pt);
int		draw_bresenham_line(t_pic	*img, t_point	start, t_point	end);
void	change_42fdf_color(t_map	*map);

// hook controls
void	hook_control(t_vars	*all);
int		close_fdf(t_vars	*all);

//bonus
void	reset_map(t_vars	*all);
void	rotate_x(t_map	*map, float_t	angle);
void	rotate_y(t_map	*map, float_t	angle);
void	scale_z(t_vars	*all, float_t	factor);
void	translate(t_map	*map, t_point	offset);
void	re_translate(t_map	*map);
void	render_instructions(t_vars	*all);
void	hook_control_bonus(t_vars	*all);

void	free_fdf(int flag, ...);

#endif