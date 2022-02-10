/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:08:27 by rjada             #+#    #+#             */
/*   Updated: 2022/02/11 00:44:36 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// int key_handler(int key, t_map *map)
// {
//     // printf("%i\n", key);
//     if (key == 65307)
//         exit(0);
//     if (key == 65362)
//         map->shift_y -= 10;
//     if (key == 65364)
//         map->shift_y += 10;
//     if (key == 65361)
//         map->shift_x -= 10;
//     if (key == 65363)
//         map->shift_x += 10;
//     mlx_clear_window(map->mlx_ptr, map->win_ptr);
//     draw_map(map);
//     return (0);
// }



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
    env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, &env->line_length, &env->endian);
    if (!env->addr)
        true_exit("Graphics mode init error", env);
}

void    set_allign_values(t_fdf *env)
{
    // env->width = 100;
    // env->height = 100;
    env->zoom = W_HEIGHT / env->height / 2;
    env->shift_x = W_WIDTH - (env->width * env->zoom) / 2;
    env->shift_y = W_HEIGHT - (env->height * env->zoom) / 2;
    // env->axis = 0;
}

int main(int argc, char **argv)
{
    t_fdf    *env;

    if (argc != 2)
        true_exit("Args", NULL);
    env = (t_fdf *)malloc(sizeof(t_fdf));
    if (!env)
        true_exit("Memory allocation error", NULL);
    // ft_memset(env, 0, sizeof(t_fdf));
    read_map(argv[1], env);
    // init_graph_mode(env);
    // set_allign_values(env);
    // draw_map(map);
    // mlx_key_hook(map->win_ptr, key_handler, map);
    // mlx_loop(env->mlx_ptr);
    printf("%d %d\n", env->width, env->height);
    for (int i = 0; i < env->height; ++i)
    {
        for (int j = 0; j < env->width; ++j)
            printf("%3d", env->coord_map[i][j]);
        printf("\n");
    }
}
