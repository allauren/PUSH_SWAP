/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 03:17:32 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 04:47:39 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2pile		*ft_checkswapbg(t_2pile *pile)
{
	if (PILEBVAL < PILEBNEX->value && ft_set_values("sb\n", 0))
		PILEB = ft_swap(PILEB, PILEBNEX);
	return (pile);
}

void		ft_sorti2(t_2pile *pile)
{
	pile = ft_checkswapbg(pile);
}

void		ft_sorti3(t_2pile *pile)
{
	if (ft_is_finish(PILEBNEX) && PILEBVAL < ft_2listtail(PILEB)->value)
		pile = ft_checkswapbg(pile);
	else if (!ft_is_reverse(PILEBNEX)
			&& ft_2listhead(PILEB)->value < ft_2listtail(PILEB)->value
			&& ft_set_values("rrb\n", 0))
	{
		PILEB = ft_2listrevrotate(PILEB);
		pile = ft_checkswapbg(pile);
	}
	else if (PILEBVAL < PILEBNEX->value && ft_set_values("rrb\n", 0))
		PILEB = ft_2listrevrotate(PILEB);
	else if (ft_set_values("rb\n", 0))
	{
		PILEB = ft_2listrotate(PILEB);
		pile = ft_checkswapbg(pile);
	}
}

void		sort_smallb(t_2pile *pile, int size)
{
	if (!size)
		return ;
	if ((size == 1 || ft_is_finish(PILEB)))
		return ;
	if (size == 2)
		ft_sorti2(pile);
	else
		ft_sorti3(pile);
}

void		sort_tillfif(t_2pile *pile, int i)
{
	while (ft_2listsize(PILEB) < i / 2 && ft_set_values("pb\n", 0))
		ft_pushb(pile);
	sort_smallb(pile, ft_2listsize(PILEB));
	sort_smalla(pile, ft_2listsize(PILEA));
	while (PILEB || !ft_is_finish(PILEA))
	{
		if (PILEB && PILEAVAL > PILEBVAL
				&& (ft_is_finish(PILEA)
					|| PILEBVAL > ft_2listtail(PILEA)->value)
				&& ft_set_values("pa\n", 0))
			ft_pusha(pile);
		else if (PILEB && PILEAVAL < ft_2listtail(PILEA)->value
				&& PILEBVAL > ft_2listtail(PILEA)->value
				&& ft_set_values("pa\n", 0) && ft_set_values("ra\n", 0))
		{
			ft_pusha(pile);
			PILEA = ft_2listrotate(PILEA);
		}
		else if (ft_set_values("ra\n", 0))
			PILEA = ft_2listrotate(PILEA);
	}
	ft_set_values(NULL, i);
}
