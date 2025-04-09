/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:02 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:17:41 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	vec_add(t_point	p1, t_point	p2)
{
	t_point	sum;

	sum.x = p1.x + p2.x;
	sum.y = p1.y + p2.y;
	sum.z = p1.z + p2.z;
	sum.color = p1.color;
	return (sum);
}

t_point	vec_sub(t_point	p1, t_point	p2)
{
	t_point	diff;

	diff.x = p1.x - p2.x;
	diff.y = p1.y - p2.y;
	diff.z = p1.z - p2.z;
	diff.color = p1.color;
	return (diff);
}

t_point	multi_mat(t_mat	mat, t_point	p)
{
	t_point	res;

	res.x = mat.x1y1 * p.x + mat.x2y1 * p.y + mat.x3y1 * p.z;
	res.y = mat.x1y2 * p.x + mat.x2y2 * p.y + mat.x3y2 * p.z;
	res.z = mat.x1y3 * p.x + mat.x2y3 * p.y + mat.x3y3 * p.z;
	res.color = p.color;
	return (res);
}
