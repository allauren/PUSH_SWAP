/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:45:27 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 17:51:20 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void		ft_easy_sort(t_2pile *pile, int i)
{
	while (ft_2listsize(pile->pileb) < i/2 && ft_set_values("pb\n", 0))
		ft_pushb(pile);
	while(!ft_is_finish(pile->pilea) || !ft_is_finish(pile->pileb))
	{
	if (ft_2listsize(pile->pilea) > 1 && ft_2listsize(pile->pilea) > 1
			&& pile->pilea->value > pile->pilea->next->value
			&& pile->pileb->value > pile->pileb->next->value && ft_set_values("ss\n", 0))
	{
		ft_swap(pile->pilea, pile->pilea->next);
		ft_swap(pile->pileb, pile->pileb->next);
	}
	else if (ft_2listsize(pile->pilea) > pile->pilea->value > pile->pilea->next->value && ft_set_values("sa\n", 0))
		ft_swap(pile->pilea, pile->pilea->next);
	else if (pile->pileb->value > pile->pileb->next->value && ft_set_values("sb\n", 0))
		ft_swap(pile->pileb, pile->pileb->next);
	if(ft_2listtail(pile->pilea)->value < ft_2listhead(pile->pilea)->value
			 && ft_2listtail(pile->pileb)->value < ft_2listhead(pile->pileb)->value
			&& ft_set_values("rrr\n", 0))
	{
		pile->pilea = ft_2listrevrotate(pile->pilea);
		pile->pileb = ft_2listrevrotate(pile->pileb);
	}
	else if(ft_2listtail(pile->pileb)->value < ft_2listhead(pile->pileb)->value && (ft_set_values("rrb\n", 0)))
		pile->pileb = ft_2listrevrotate(pile->pileb);
	else if(ft_2listtail(pile->pilea)->value < ft_2listhead(pile->pilea)->value && (ft_set_values("rra\n", 0)))
		pile->pilea = ft_2listrevrotate(pile->pilea);
	else if(ft_set_values("rrr\n", 0))
	{
	ft_printf("coucou");
		pile->pilea = ft_2listrotate(pile->pilea);
		pile->pileb = ft_2listrotate(pile->pileb);
	}
	ft_print_pile(pile);
	}
	while(pile->pileb && !ft_is_finish(pile->pilea))
	{
		if((ft_2listhead(pile->pileb)->value < ft_2listhead(pile->pilea)->value )
			|| (ft_is_finish(pile->pilea) 
			&& ft_2listhead(pile->pileb)->value > ft_2listtail(pile->pilea)->value))
		{
			ft_pusha(pile);
			ft_set_values("pa\n", 0);
		}
		else if(ft_set_values("ra\n", 0))
			pile->pilea = ft_2listrotate(pile->pilea);
	}
}*/
