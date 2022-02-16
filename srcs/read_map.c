/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:10 by rjada             #+#    #+#             */
/*   Updated: 2022/02/17 00:11:18 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *src, char sep)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && src[i] == sep)
			++i;
		if (src[i] && src[i] != sep)
		{
			++total;
			while (src[i] && src[i] != sep)
				++i;
		}
	}
	return (total);
}

static void	get_height_and_width(char *file_name, t_fdf *env)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (!fd)
		true_exit(OPEN_ERR, env);
	line = get_next_line(fd);
	if (!line)
		true_exit(MAP_ERR, env);
	env->width = count_words(line, ' ');
	env->height = 0;
	while (line)
	{
		free(line);
		++(env->height);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	fill_matrix(int *coords, char *line)
{
	char	**cells;
	int		i;

	cells = ft_split(line, ' ');
	i = 0;
	while (cells[i])
	{
		coords[i] = ft_atoi(cells[i]);
		++i;
	}
	ft_split_free(cells);
}

static int	**matrix_malloc(int height, int width)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * (height + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		++i;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	read_map(char *file_name, t_fdf *env)
{
	int		i;
	int		fd;
	char	*line;

	get_height_and_width(file_name, env);
	env->coord_map = matrix_malloc(env->height, env->width);
	if (!env->coord_map)
		true_exit(MEM_ERR, env);
	fd = open(file_name, O_RDONLY);
	if (!fd)
		true_exit(OPEN_ERR, env);
	i = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(env->coord_map[i], line);
		++i;
		free(line);
	}
	close(fd);
}
