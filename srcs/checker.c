/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:10:37 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 08:40:32 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_usage(void)
{
	ft_printf("usage: ./checker valid input numbers\n");
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
		ft_printf("Error\n");
		return (-1);
	}
	pile.pilea = ft_fill(pile.pilea, tab, i);
	ft_memdel((void**)&tab);
	ft_readpsw(&pile);
	ft_2lstdelall(pile.pilea);
	ft_2lstdelall(pile.pileb);
	return (0);
}
