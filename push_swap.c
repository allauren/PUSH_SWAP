/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:38:24 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 03:08:29 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	insertion_sort(&pile, i);
	quick2sort(&pile, 0, i);
//	ft_easy_sort(&pile, i);
 ft_set_values(NULL, -1);
ft_print_pile(&pile);
	ft_2lstdelall(pile.pilea);
	ft_2lstdelall(pile.pileb);
	return 0;
}
/*
int		ft_is_smallest(t_2list *pile)
{
	int key;

	if (pile)
		key = pile->value;
	while (pile)
	{
		pile = pile->next;
		if (pile && pile->value < key)
			return (0);
	}
	return (1);
}
t_2pile		*ft_is_opti(t_2pile *pile, int *lenb)
{
	int		i;

	i = 0;
	ft_print_pile(pile);
	while(PILEB && PILEBNEX && ++i < 4 && ft_is_smallest(PILEB))
		PILEB = PILEBNEX;
	PILEB = ft_2listhead(PILEB);
	sort_small(pile, i);
	ft_print_pile(pile);
	*lenb -= i;
	return(pile);
}

*/
