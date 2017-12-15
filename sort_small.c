/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:32:25 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 02:51:45 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_reverse(t_2list *pile)
{
	while (pile && pile->next)
	{
		if (pile->value < pile->next->value)
			return(0);
		pile = pile->next;
	}
	return (1);
}

t_2pile	*ft_checkswapb(t_2pile *pile)
{
	///ft_printf("%d et next %d", PILEBVAL, PILEBNEX->value);
	if(PILEBVAL < PILEBNEX->value && PILEAVAL > PILEANEX->value
			&& ft_set_values("ss\n", 0))
	{
		PILEA = ft_swap(PILEA, PILEANEX);
		PILEB = ft_swap(PILEB, PILEBNEX);
	}
	else if (PILEBVAL < PILEBNEX->value && ft_set_values("sb\n", 0))
		PILEB = ft_swap(PILEB, PILEBNEX);
	//ft_printf("PILEB %d et PILEBNEX %d", PILEBVAL, PILEBNEX->value);
	return (pile);
}

int	ft_pushrota(t_2pile *pile, int len)
{
	while (PILEB && ft_set_values("pa\n", 0))
		ft_pusha(pile);
	while (len-- && ft_set_values("ra\n", 0))
		PILEA = ft_2listrotate(PILEA);
	return (1);
}

void	ft_sort2(t_2pile *pile, int len)
{
	pile = ft_checkswapb(pile);
	ft_pushrota(pile, len);
}

void	ft_sort3(t_2pile *pile, int len)
{
	if (ft_is_reverse(PILEBNEX) && PILEBVAL > ft_2listtail(PILEB)->value)
		pile = ft_checkswapb(pile);
	else if (!ft_is_reverse(PILEBNEX) 
			&& ft_2listhead(PILEB)->value > ft_2listtail(PILEB)->value
			&& ft_set_values("rrb\n", 0))
	{
		PILEB = ft_2listrevrotate(PILEB);
		pile = ft_checkswapb(pile);
	}
	else if (PILEBVAL > PILEBNEX->value && ft_set_values("rrb\n", 0))
		PILEB = ft_2listrevrotate(PILEB);
	else if (ft_set_values("rb\n", 0))
	{
		PILEB = ft_2listrotate(PILEB);
		pile = ft_checkswapb(pile);
	}
	ft_pushrota(pile, len);
}

void	sort_small(t_2pile *pile, int size)
{
	if (!size)
		return;
	if ((size == 1 || ft_is_reverse(PILEB)) && ft_pushrota(pile, size))
		return;
	if (size == 2)
		ft_sort2(pile, size);
	else
		ft_sort3(pile, size);
}
