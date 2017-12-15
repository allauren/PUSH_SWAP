/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechpushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:55:58 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 06:03:16 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_finish(t_2list *pilea)
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
				return (0);
			}
		}
		else
			break ;
	}
	return (1);
}

int		ft_is_reverse(t_2list *pile)
{
	while (pile && pile->next)
	{
		if (pile->value < pile->next->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}
