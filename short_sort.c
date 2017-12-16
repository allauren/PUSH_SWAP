/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:59:25 by allauren          #+#    #+#             */
/*   Updated: 2017/12/16 22:49:36 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2pile		*ft_checkswapa(t_2pile *pile)
{
	if (PILEAVAL > PILEANEX->value && ft_set_values("sa\n", 0))
		PILEA = ft_swap(PILEA, PILEANEX);
	return (pile);
}

void		ft_sorta3(t_2pile *pile)
{
	if (ft_is_finish(PILEANEX) && PILEAVAL < ft_2listtail(PILEA)->value)
		pile = ft_checkswapa(pile);
	else if (!ft_is_finish(PILEANEX)
			&& ft_2listhead(PILEA)->value < ft_2listtail(PILEA)->value
			&& ft_set_values("rra\n", 0))
	{
		PILEA = ft_2listrevrotate(PILEA);
		pile = ft_checkswapa(pile);
	}
	else if (PILEAVAL < PILEANEX->value && ft_set_values("rra\n", 0))
		PILEA = ft_2listrevrotate(PILEA);
	else if (ft_set_values("ra\n", 0))
	{
		PILEA = ft_2listrotate(PILEA);
		pile = ft_checkswapa(pile);
	}
}

void		sort_smalla(t_2pile *pile, int size)
{
	if (!size)
		return ;
	if ((size == 1 || ft_is_finish(PILEA)))
		return ;
	if (size == 2)
		pile = ft_checkswapa(pile);
	else
		ft_sorta3(pile);
}
