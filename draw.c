/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:54 by rjada             #+#    #+#             */
/*   Updated: 2022/02/09 21:44:00 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int get_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

void    isometric(float *x, float *y, int z)
{
    int prev_x;
    int prev_y;

    prev_x = *x;
    prev_y = *y;
    *x = (prev_x - prev_y) * cos(0.523599);
    *y = (prev_x + prev_y) * sin(0.523599) - z;
}

void    draw_line(float x0, float y0, float x1, float y1, t_map *map)
{
    float len_x;
    float len_y;
    int len;
    int dx;
    int dy;
    int z0;
    int z1;

    z0 = map->peaks[(int)y0][(int)x0];
    z1 = map->peaks[(int)y1][(int)x1];

    x0 *= map->zoom;
    x1 *= map->zoom;
    y0 *= map->zoom;
    y1 *= map->zoom;
    z0 *= map->zoom;
    z1 *= map->zoom;

    isometric(&x0, &y0, z0);
    isometric(&x1, &y1, z1);

    x0 += map->shift_x;
    y0 += map->shift_y;
    x1 += map->shift_x;
    y1 += map->shift_y;

    dx = (x1 - x0 >= 0 ? 1 : -1);
    dy = (y1 - y0 >= 0 ? 1 : -1);
    len_x = ft_abs(x1 - x0);
    len_y = ft_abs(y1 - y0);
    len = get_max(len_x, len_y);
    if (len_y <= len_x)
    {
        while (len-- >= 0)
        {
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, roundf(y0), map->color);
            x0 += dx;
            y0 += dy * len_y / len_x;
        }
    }
    else
    {
        while (len-- >= 0)
        {
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, roundf(x0), y0,  map->color);
            x0 += dx * len_x / len_y;
            y0 += dy;
        }
    }
}

void    draw_map(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            map->color = map->color_map[y][x];
            if (x < map->width - 1)
                draw_line(x, y, x + 1, y, map);
            if (y < map->height - 1)
                draw_line(x, y, x, y + 1, map);
            ++x;
        }
        ++y;
    }
}