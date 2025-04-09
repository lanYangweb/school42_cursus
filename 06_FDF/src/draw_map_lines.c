/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:39 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:23:27 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
Line drawing implementation using Bresenham's Line Algorithmm.
See:
https://www.markwrobel.dk/post/amiga-machine-code-letter12-linedraw/
*/

void	put_pixel(t_pic	*img, t_point	pt)
{
	char	*dst;
	int		x;
	int		y;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_pix / 8));
	*(unsigned int *)dst = pt.color;
}

static int	draw_low_line(t_pic	*img, t_point	s, t_point	e)
{
	double	err;
	double	slope;
	double	step;
	t_point	cur;

	slope = (double)(e.y - s.y) / (e.x - s.x);
	err = -0.5;
	step = fabs(slope);
	cur = s;
	while (cur.x < e.x)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (slope > 0)
				cur.y++;
			else
				cur.y--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.x++;
	}
	return (0);
}

static int	draw_high_line(t_pic	*img, t_point	s, t_point	e)
{
	double	err;
	double	tr_slope;
	double	step;
	t_point	cur;

	tr_slope = (double)(e.x - s.x) / (e.y - s.y);
	err = -0.5;
	step = fabs(tr_slope);
	cur = s;
	while (cur.y < e.y)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (tr_slope > 0)
				cur.x++;
			else
				cur.x--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.y++;
	}
	return (0);
}

int	draw_bresenham_line(t_pic	*img, t_point	start, t_point	end)
{
	if (fabs(end.y - start.y) < fabs(end.x - start.x))
	{
		if (end.x < start.x)
			return (draw_low_line(img, end, start));
		return (draw_low_line(img, start, end));
	}
	if (end.y < start.y)
		return (draw_high_line(img, end, start));
	return (draw_high_line(img, start, end));
}
