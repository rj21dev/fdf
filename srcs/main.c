/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:08:27 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 23:58:21 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_graph_mode(t_fdf *env)
{
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		true_exit(GRAPH_ERR, env);
	env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, W_HEADER);
	if (!env->win_ptr)
		true_exit(GRAPH_ERR, env);
	env->img = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!env->img)
		true_exit(GRAPH_ERR, env);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, \
									&env->line_len, &env->endian);
	if (!env->addr)
		true_exit(GRAPH_ERR, env);
}

static void	init_camera(t_fdf *env)
{
	env->color = COLOR;
	if (env->height < 200)
	{
		env->altitude = 3;
		env->zoom = W_HEIGHT / env->height / 2;
		env->shift_x = W_WIDTH / 2 - env->width / 2;
		env->shift_y = W_HEIGHT / 2 - env->height * env->zoom / 2;
	}
	else
	{
		env->altitude = 1;
		env->zoom = W_HEIGHT / 400;
		env->shift_x = W_WIDTH / 2;
		env->shift_y = W_HEIGHT / 2 - env->height * env->zoom / 2;
	}
}

static int	is_valid_suffix(char *argv, char *suf)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == suf[0])
		{
			j = 0;
			while (argv[i + j] == suf[j])
			{
				if (suf[j + 1] == 0)
					return (TRUE);
				++j;
			}
		}
		++i;
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2 || !is_valid_suffix(argv[1], ".fdf"))
		true_exit(ARG_ERR, NULL);
	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		true_exit(MEM_ERR, NULL);
	read_map(argv[1], env);
	init_graph_mode(env);
	init_camera(env);
	render_map(env);
	events_handler(env);
	mlx_loop(env->mlx_ptr);
}
