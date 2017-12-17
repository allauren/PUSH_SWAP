/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:47:27 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 13:58:58 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_count_push(char *tmp, int i2)
{
	int		cpa;
	int		cpb;
	int		i;

	i = 0;
	cpa = 0;
	cpb = 0;
	while (i < i2)
	{
		if (!ft_strncmp(&tmp[i], "pa\n", 3))
			cpa++;
		if (!ft_strncmp(&tmp[i], "pb\n", 3))
			cpb++;
		i += ft_strchr(&tmp[i], '\n') - &tmp[i] + 1;
	}
	return (cpb - cpa);
}

char		*ft_short_string(char *s, int taille, char *tmp)
{
	int		i;
	int		count;

	i = 0;
	if (!(s = ft_memalloc(ft_strlen(s) + 1)))
		ft_exit();
	while (tmp[i + 1] && ((count = 0) + 1))
	{
		while (tmp[i + 1] && ft_strncmp(&tmp[i], "ra\n", 3))
		{
			s = ft_strncat(s, &tmp[i], ft_strchr(&tmp[i], '\n') - &tmp[i] + 1);
			i += ft_strchr(&tmp[i], '\n') - &tmp[i] + 1;
		}
		while (tmp[i + 1] && !ft_strncmp(&tmp[i], "ra\n", 3) && ++count)
			i += ft_strchr(&tmp[i], '\n') - &tmp[i] + 1;
		if (count > taille / 2)
			while (count++ < taille - ft_count_push(&tmp[0], i))
				ft_strcat(s, "rra\n");
		else
			while (count--)
				ft_strcat(s, "ra\n");
	}
	ft_strdel(&tmp);
	return (s);
}
