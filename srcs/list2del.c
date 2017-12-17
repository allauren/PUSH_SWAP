/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2listdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:12:17 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 08:22:38 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_2listdel(t_2list *begin)
{
	t_2list	*prov;

	prov = NULL;
	if (!begin)
		return ;
	begin->next = NULL;
	begin->head = NULL;
	ft_memdel((void**)&begin);
}

t_2list		*ft_2listndel(t_2list *begin, int n)
{
	int		i;
	t_2list *temp;
	t_2list	*prev;
	t_2list	*next;

	temp = begin;
	i = -1;
	while (((next = NULL) + 1) && begin && ++i < n
			&& (prev = begin))
		begin = begin->next;
	if (i == n)
	{
		if (!begin->head)
			temp = begin->next;
		if (begin->next)
			next = begin->next;
		if (prev)
		{
			next->head = prev;
			prev->next = begin->next;
		}
		ft_2listdel(begin);
	}
	return (temp);
}

void		ft_2lstdelall(t_2list *begin)
{
	t_2list *prov;

	prov = begin;
	if (begin)
	{
		while (begin->head)
			begin = begin->head;
		while (begin)
		{
			if (begin->next)
			{
				prov = begin;
				begin = begin->next;
				ft_2listdel(prov);
			}
			else
			{
				ft_2listdel(begin);
				begin = NULL;
			}
		}
	}
}
