/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:16 by rjada             #+#    #+#             */
/*   Updated: 2022/02/16 23:31:45 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	hextoi(char *hexstr)
{
	int	len;
	int	pow_base;
	int	res;

	res = 0;
	pow_base = 1;
	len = ft_strlen(hexstr) - 1;
	while (len >= 0)
	{
		if (ft_isdigit(hexstr[len]))
			res += pow_base * (hexstr[len] - 48);
		if (hexstr[len] >= 'a' && hexstr[len] <= 'f')
			res += pow_base * (hexstr[len] - 87);
		if (hexstr[len] >= 'A' && hexstr[len] <= 'F')
			res += pow_base * (hexstr[len] - 55);
		pow_base *= 16;
		--len;
	}
	return (res);
}
