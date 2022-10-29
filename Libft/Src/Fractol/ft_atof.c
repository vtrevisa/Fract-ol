/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:39:28 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/29 14:04:51 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	conversions(t_lst *lst, const char *str)
{
	lst->temp = str[lst->i];
	while (ft_isdigit(lst->temp))
	{
		lst->ret = lst->ret * 10 + (lst->temp - 48);
		lst->temp = str[++lst->i];
	}
	if (lst->temp == '.')
	{
		lst->temp = str[++lst->i];
		while (ft_isdigit(lst->temp) && ++lst->p_vir)
		{
			lst->ret = lst->ret * 10 + (lst->temp - 48);
			lst->temp = str[++lst->i];
		}
	}
	while (lst->p_vir > 0)
	{
		lst->ret /= 10;
		lst->p_vir--;
	}
}

double	ft_atof(const char *str)
{
	t_lst	lst;

	lst.ret = 0.0;
	lst.p_vir = 0;
	lst.i = 0;
	conversions(&lst, str);
	return (lst.ret);
}
