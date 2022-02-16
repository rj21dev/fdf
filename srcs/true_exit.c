/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:22 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 23:30:19 by rjada            ###   ########.fr       */
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

void	true_exit(char *errmsg, t_fdf *env)
{
	if (env)
	{
		if (env->coord_map)
			matrix_free(env->coord_map);
		free(env);
	}
	if (errno == 0)
		ft_putendl_fd(errmsg, STDERR);
	else
		perror(errmsg);
	exit(EXIT_FAILURE);
}
