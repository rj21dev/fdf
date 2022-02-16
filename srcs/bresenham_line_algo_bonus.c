/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algo_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:28:25 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 23:30:47 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	best_pixel_put(t_fdf *env, int x, int y, int color)
{
	char	*addr;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		addr = env->addr + (y * env->line_len + x * (env->bpp / 8));
		*(unsigned int *)addr = color;
	}
}

static int	get_sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

static t_param	*pre_algo_init(t_dot *a, t_dot *b, t_fdf *env)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		true_exit("Malloc error", env);
	param->delta_x = ft_abs(b->x - a->x);
	param->delta_y = ft_abs(b->y - a->y);
	param->sign_x = get_sign(a->x, b->x);
	param->sign_y = get_sign(a->y, b->y);
	param->err = param->delta_x - param->delta_y;
	return (param);
}

void	bresenham(t_dot *a, t_dot *b, t_fdf *env)
{
	t_param	*param;

	param = pre_algo_init(a, b, env);
	while (a->x != b->x || a->y != b->y)
	{
		best_pixel_put(env, a->x, a->y, env->color);
		param->err2 = param->err * 2;
		if (param->err2 > -param->delta_y)
		{
			param->err -= param->delta_y;
			a->x += param->sign_x;
		}
		if (param->err2 < param->delta_x)
		{
			param->err += param->delta_x;
			a->y += param->sign_y;
		}
	}
	free(param);
	free(a);
	free(b);
}
