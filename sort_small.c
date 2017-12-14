/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:32:25 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 20:13:17 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_reverse(t_2pile *pile)
{
	while (PILEB && PILEBNEX)
	{
		if (PILEBVAL > PILEBNEX->value)
			return(0);
		PILEB = PILEBNEX;
	}
	return (1);
}

void	ft_checkswapb(t_2pile *pile)
{
	if(PILEBVAL < PILEBNEX->value && PILEAVAL > PILEANEX->value
			&& ft_set_values("ss\n", 0))
	{
		ft_swap(PILEA, PILEANEX);
		ft_swap(PILEB, PILEBNEX);
	}
	else if (PILEBVAL < PILEBNEX->value && ft_set_values("sb\n", 0))
		ft_swap(PILEB, PILEBNEX);
}
void	ft_pushrota(t_2pile *pile, int len)
{
	int len2;

	len2 = len;
	while (len-- && ft_set_values("pa\n", 0))
		ft_pusha(pile);
	while(len2-- && ft_set_values("ra\n", 0))
			PILEA = ft_2listrotate(PILEA);
}

void	ft_sort2(t_2pile *pile, int len)
{
	ft_checkswapb(pile);
	ft_pushrota(pile, len);
}

void	sort_small(t_2pile *pile, int size)
{
	if (size == 1 || ft_is_reverse(pile))
		return;
	ft_sort2(pile, size);
}
