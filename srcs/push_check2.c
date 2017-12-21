/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 07:10:01 by allauren          #+#    #+#             */
/*   Updated: 2017/12/21 05:29:23 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_is(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && i != 0)
			return (0);
	}
	return (1);
}

void		ft_is_sort(t_2list *pilea)
{
	int		temp;

	while (pilea && pilea->next)
	{
		temp = pilea->value;
		if (pilea->next)
		{
			pilea = pilea->next;
			if (temp > pilea->value)
			{
				ft_printf("KO\n");
				return ;
			}
		}
		else
			break ;
	}
	ft_printf("OK\n");
}

int			ft_ispresent(int *tab, int i)
{
	int j;
	int c;

	c = tab[i];
	j = i;
	while (--j > -1)
	{
		if (tab[j] == c)
			return (0);
	}
	return (1);
}

int			ft_fullzero(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (str[i] != '0')
			return (0);
	return (1);
}
