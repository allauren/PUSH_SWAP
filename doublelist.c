/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:37:23 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 22:46:57 by allauren         ###   ########.fr       */
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

int		ft_2listsize(t_2list *begin)
{
	int		i;

	i = 0;
	begin= ft_2listhead(begin);
	while (begin && begin->next && ++i)
		begin = begin->next;
	return (++i);
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
/*
int			main(int argc, const char *argv[])
{
	t_2list	*pilea;
	t_2list	*pileanext;
	t_2list	*pileb;
	int i;

	i = 0;
	pileb = NULL;
	pilea = ft_2list_new(i);
	while (i < 10)
		ft_2listfront(ft_2list_new(++i), pilea);
	i = 0;
	pileanext = pilea->next;
	pileb = ft_push(pilea, pileb);
	pilea = pileanext;
	pileanext = pilea->next;
	pileb = ft_push(pilea, pileb);
	pilea = pileanext;
	while (pileb)
	{
		ft_printf("%d\n", pileb->value);
		if(pileb->next)
			pileb = pileb->next;
		else
			break;
	}
	ft_printf("\nfin de la pile\n");
	while (pilea)
	{
		ft_printf("%d\n", pilea->value);
		if(pilea->next)
		pilea = pilea->next;
		else
			break;
	}
	pilea = ft_2listrevrotate(pilea);
	ft_2lstdelall(pilea);
	ft_2lstdelall(pileb);
	return 0;
}*/
