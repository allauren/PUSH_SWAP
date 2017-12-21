/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechpushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:55:58 by allauren          #+#    #+#             */
/*   Updated: 2017/12/21 06:13:07 by allauren         ###   ########.fr       */
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

int		ft_is_nfinish(t_2pile *pile, int n)
{
	int		temp;

	PILEA = ft_2listhead(PILEA);
	while (PILEA && PILEA->next && n--)
	{
		temp = PILEA->value;
		if (PILEA->next)
		{
			PILEA = PILEA->next;
			if (temp > PILEA->value)
			{
				PILEA = ft_2listhead(PILEA);
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

void	ft_find_opti(int lenb, t_2pile *pile, int *tab, int i)
{
	if (lenb)
	{
		PILEA = ft_2listhead(PILEA);
		while (i > 0 && tab[i - 1] && ft_is_nfinish(pile, tab[i - 1]))
		{
			while (tab[i - 1])
			{
				ft_set_values("ra\n", 0);
				PILEA = ft_2listrotate(PILEA);
				tab[i - 1] -= 1;
			}
			i--;
		}
		if (i)
		{
			lenb -= ft_reinit(pile, tab[i - 1]);
			tab[i - 1] = 0;
			ft_2sortb(pile, lenb, tab);
		}
	}
}
