/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:38:24 by allauren          #+#    #+#             */
/*   Updated: 2017/12/18 15:37:38 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_algo(t_2pile *pile, int i)
{
	if (i > 3 && ft_is_nfinish(PILEA, i - 2)
			&& ft_2listtail(PILEA)->value < ft_2listhead(PILEA)->value
			&& ft_2listtail(PILEA)->head->value < ft_2listhead(PILEA)->value
			&& ft_set_values("rra\n", 0) && ft_set_values("rra\n", 0))
	{
		PILEA = ft_2listrevrotate(PILEA);
		PILEA = ft_2listrevrotate(PILEA);
		pile = ft_checkswapa(pile);
	}
	if (i > 3 && ft_is_nfinish(PILEA, i - 1)
			&& ft_2listtail(PILEA)->value < ft_2listhead(PILEA)->value
			&& ft_set_values("rra\n", 0))
		PILEA = ft_2listrevrotate(PILEA);
	if (!(ft_is_finish(pile->pilea)))
	{
		if (i < 4)
			sort_smalla(pile, i);
		else if (i > 6)
		quick2sort(pile, 0, i);
		else
			sort_tillfif(pile, i);
	}
	ft_set_values(NULL, -1);
}

static int	ft_usage(void)
{
	ft_printf("usage: ./push_swap valid input numbers\n");
	return (-1);
}

int			main(int argc, char *argv[])
{
	t_2pile		pile;
	int			*tab;
	int			i;

	if (argc < 2)
		return (ft_usage());
	i = ft_cut(argc, argv);
	ft_bzero(&pile, sizeof(t_2pile));
	if (!(tab = ft_memalloc(sizeof(int) * (i))))
		ft_exit();
	if (!ft_checker(argc, argv, tab) || argc < 2)
	{
		ft_memdel((void**)&tab);
		return (-1);
	}
	pile.pilea = ft_fill(pile.pilea, tab, i);
	ft_memdel((void**)&tab);
	if (!(ft_is_finish(pile.pilea)))
		ft_check_algo(&pile, i);
//ft_print_pile(pile.pilea, pile.pileb, 0);
//	if(ft_is_finish(pile.pilea))
//		ft_printf("algo a bien trie");
	ft_2lstdelall(pile.pilea);
	ft_2lstdelall(pile.pileb);
	return (0);
}
