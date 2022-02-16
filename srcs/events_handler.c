/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:31:49 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 22:23:51 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	matrix_free(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	close_win(t_fdf *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	matrix_free(env->coord_map);
	free(env);
	exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_fdf *env)
{
	if (key == 65307)
		close_win(env);
	return (0);
}

void	events_handler(t_fdf *env)
{
	mlx_key_hook(env->win_ptr, key_handler, env);
	mlx_hook(env->win_ptr, 17, 0, close_win, env);
}
