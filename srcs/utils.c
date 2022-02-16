/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:16 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 22:22:10 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_suffix(char *argv, char *suf)
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
