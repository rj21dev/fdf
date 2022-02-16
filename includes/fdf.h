/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:59:25 by rjada             #+#    #+#             */
/*   Updated: 2022/02/17 00:10:32 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>

# define W_HEADER "FdF (Fils de Fer) wireframe"
# define W_WIDTH 1800
# define W_HEIGHT 1000
# define COLOR 0xfea100
# define MEM_ERR "Memory allocation error"
# define GRAPH_ERR "Graphics mode init error"
# define OPEN_ERR "Open error"
# define MAP_ERR "Map error"
# define ARG_ERR "Usage: ./fdf map.fdf"

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		**coord_map;
	int		zoom;
	int		color;
	int		altitude;
	int		shift_x;
	int		shift_y;
}				t_fdf;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
}				t_dot;

typedef struct s_param
{
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	err;
	int	err2;
}				t_param;

void	bresenham(t_dot *a, t_dot *b, t_fdf *env);
void	render_map(t_fdf *env);
void	read_map(char *file_name, t_fdf *env);
void	true_exit(char *errmsg, t_fdf *env);
void	events_handler(t_fdf *env);

#endif
