/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:54 by rjada             #+#    #+#             */
/*   Updated: 2022/02/17 00:12:10 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}

static t_dot	*projection(t_dot *dot, t_fdf *env)
{
	dot->x *= env->zoom;
	dot->y *= env->zoom;
	dot->z *= env->altitude;
	isometric(&dot->x, &dot->y, dot->z);
	dot->x += env->shift_x;
	dot->y += env->shift_y;
	return (dot);
}

static t_dot	*get_coord(int x, int y, t_fdf *env)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (!dot)
		true_exit(MEM_ERR, env);
	dot->x = x;
	dot->y = y;
	dot->z = env->coord_map[y][x];
	return (dot);
}

void	render_map(t_fdf *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			if (x < env->width - 1)
				bresenham(projection(get_coord(x, y, env), env), \
				projection(get_coord(x + 1, y, env), env), env);
			if (y < env->height - 1)
				bresenham(projection(get_coord(x, y, env), env), \
				projection(get_coord(x, y + 1, env), env), env);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
}
