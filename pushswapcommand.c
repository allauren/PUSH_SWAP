/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswzpcommand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:07:03 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 07:11:53 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2list		*ft_2listrevrotate(t_2list *begin)
{
	t_2list	*next;
	t_2list	*tail;
	int		index;

	if (!begin || !begin->next)
		return (begin);
	begin = ft_2listhead(begin);
	index = begin->index;
	tail = ft_2listtail(begin);
	next = tail->head;
	begin->head = tail;
	tail->next = begin;
	tail->head = NULL;
	next->next = NULL;
	return (tail);
}

t_2list		*ft_2listrotate(t_2list *begin)
{
	t_2list	*tail;
	t_2list	*head;

	if (!begin || !begin->next)
		return (begin);
	begin = ft_2listhead(begin);
	tail = ft_2listtail(begin);
	head = begin->next;
	head->head = NULL;
	begin->next = NULL;
	begin->head = tail;
	tail->next = begin;
	return (head);
}

t_2list		*ft_swap(t_2list *begin, t_2list *next)
{
	t_2list	*temp;
	int		index;

	if (!next)
		return (begin);
	temp = next->next;
	next->head = NULL;
	next->next = begin;
	begin->next = temp;
	if (temp)
		temp->head = begin;
	begin->head = next;
	index = begin->index;
	begin->index = next->index;
	next->index = index;
	return (next);
}

void		ft_pushb(t_2pile *pile)
{
	t_2list		*nexta;

	if (!pile->pilea)
		return ;
	pile->pilea = pile->pilea ? ft_2listhead(pile->pilea) : NULL;
	pile->pileb = pile->pileb ? ft_2listhead(pile->pileb) : NULL;
	nexta = pile->pilea->next ? pile->pilea->next : NULL;
	if (pile->pilea)
		pile->pilea->next = pile->pileb;
	if (pile->pileb)
		pile->pileb->head = pile->pilea;
	if (nexta)
		nexta->head = NULL;
	pile->pileb = pile->pilea;
	pile->pilea = nexta;
}

void		ft_pusha(t_2pile *pile)
{
	t_2list		*nextb;

	if (!pile->pileb)
		return ;
	pile->pilea = pile->pilea ? ft_2listhead(pile->pilea) : NULL;
	pile->pileb = pile->pileb ? ft_2listhead(pile->pileb) : NULL;
	nextb = pile->pileb->next ? pile->pileb->next : NULL;
	if (pile->pileb)
		pile->pileb->next = pile->pilea;
	if (pile->pilea)
		pile->pilea->head = pile->pileb;
	if (nextb)
		nextb->head = NULL;
	pile->pilea = pile->pileb;
	pile->pileb = nextb;
}
