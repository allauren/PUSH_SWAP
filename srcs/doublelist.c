/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:37:23 by allauren          #+#    #+#             */
/*   Updated: 2017/12/19 01:13:36 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2list		*ft_2list_new(int value, int index)
{
	t_2list	*new;

	if (!(new = (t_2list*)malloc(sizeof(t_2list))))
		return (NULL);
	new->value = value;
	new->index = index;
	new->head = NULL;
	new->next = NULL;
	return (new);
}

t_2list		*ft_2listhead(t_2list *begin)
{
	while (begin && begin->head)
		begin = begin->head;
	return (begin);
}

t_2list		*ft_2listtail(t_2list *begin)
{
	while (begin && begin->next)
		begin = begin->next;
	return (begin);
}

int			ft_2listsize(t_2list *begin)
{
	int		i;

	i = 0;
	begin = ft_2listhead(begin);
	while (begin && begin->next && ++i)
		begin = begin->next;
	return (begin ? ++i : i);
}

t_2list		*ft_2listfront(t_2list *begin, t_2list *new)
{
	if (!new)
		return (begin);
	if (!begin)
		return (new);
	while (new->next)
		new = new->next;
	begin->head = new;
	new->next = begin;
	return (new);
}
