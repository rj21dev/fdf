/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:59:25 by rjada             #+#    #+#             */
/*   Updated: 2022/02/11 00:25:15 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# define W_HEADER "FdF (Fils de Fer) wireframe"
# define W_WIDTH 1360
# define W_HEIGHT 768


typedef struct  s_fdf
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
    int     **coord_map;
    int     **color_map;
    int     zoom;
    int     color;
    int     shift_x;
    int     shift_y;
}               t_fdf;

// void    draw_line(float x0, float y0, float x1, float y1, t_map *map);
// void    draw_map(t_map *map);
int     hextoi(char *hexstr);
void    read_map(char *file_name, t_fdf *env);
void    true_exit(char *errmsg, t_fdf *env);

#endif
