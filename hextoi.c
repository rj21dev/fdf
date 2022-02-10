/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:16 by rjada             #+#    #+#             */
/*   Updated: 2022/02/10 22:20:20 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int hextoi(char *hexstr)
{
    int  len;
    int  pow_base;
    int     res;

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
