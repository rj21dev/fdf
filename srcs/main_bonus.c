/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:08:27 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 23:31:09 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void    init_graph_mode(t_fdf *env)
{
    env->mlx_ptr = mlx_init();
    if (!env->mlx_ptr)
        true_exit("Graphics mode init error", env);
    env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, W_HEADER);
    if (!env->win_ptr)
        true_exit("Graphics mode init error", env);
    env->img = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
    if (!env->img)
        true_exit("Graphics mode init error", env);
    env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->line_len, &env->endian);
    if (!env->addr)
        true_exit("Graphics mode init error", env);
}

void    set_allign_values(t_fdf *env)
{
	env->zoom = W_HEIGHT / env->height / 2;
    env->shift_x = W_WIDTH / 2 - env->width / 2;
    env->shift_y = (W_HEIGHT / 2 - env->height / 2) - env->width * env->zoom / 2;
    // env->axis = 0;
}



int main(int argc, char **argv)
{
    t_fdf    *env;

    if (argc != 2)
        true_exit("Usage: ./fdf map.fdf", NULL);
    env = (t_fdf *)malloc(sizeof(t_fdf));
    if (!env)
        true_exit("Memory allocation error", NULL);
    read_map(argv[1], env);
    init_graph_mode(env);
    set_allign_values(env);
    render_map(env);
	events_handler(env);
    mlx_loop(env->mlx_ptr);
}
