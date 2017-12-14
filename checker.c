/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:10:37 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 17:55:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	ft_is_sort(

*/


int			main(int argc, char *argv[])
{
	t_2pile		pile;
	int			*tab;
	int			i;

	i = ft_cut(argc, argv);
	ft_bzero(&pile, sizeof(t_2pile));
	if(!(tab = ft_memalloc(sizeof(int) * (i))))
		ft_exit();
	if (!ft_checker(argc, argv, tab) || argc < 2)
	{
		ft_memdel((void**)&tab);
		ft_printf("Error\n");
		return (-1);
	}
	pile.pilea = ft_fill(pile.pilea, tab, i);
	ft_memdel((void**)&tab);
	ft_readpsw(&pile);
	ft_2lstdelall(pile.pilea);
	ft_2lstdelall(pile.pileb);
	return 0;
/*	ft_pusha(&pile);
		ft_printf("valeur%d\n",pile.pileb->value);
	ft_pusha(&pile);
	ft_pushb(&pile);
	ft_pushb(&pile);
	if (pile.pileb)
		ft_printf("valeur%d\n",pile.pileb->value);
	while (pile.pilea)
	{
		ft_printf("%d\n", pile.pilea->value);
		if(pile.pilea->next)
		pile.pilea = pile.pilea->next;
		else
			break;
	}
	ft_printf("fin de la pilea\n");
	while (pile.pileb)
	{
		ft_printf("%d\n", pile.pileb->value);
		if(pile.pileb->next)
		pile.pileb = pile.pileb->next;
		else
			break;
	}


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
		pilea = ft_2listrevrotate(pilea);
	ft_2lstdelall(pilea);
	ft_2lstdelall(pileb);*/
}
