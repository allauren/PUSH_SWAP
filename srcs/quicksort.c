/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:35 by allauren          #+#    #+#             */
/*   Updated: 2017/12/20 18:24:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_partitiona(t_2pile *pile, int key, int size)
{
	int	i;

	i = -1;
	PILEA = ft_2listhead(PILEA);
	while (PILEA && ++i < size)
		if (PILEAVAL <= key && ft_set_values("pb\n", 0))
			ft_pushb(pile);
		else if (ft_set_values("ra\n", 0))
			PILEA = ft_2listrotate(PILEA);
	return (key);
}

int		ft_partitionb(t_2pile *pile, int key, int size, int i)
{
	int		count;
	int		pa;

	pa = 0;
	count = 0;
	PILEB = ft_2listhead(PILEB);
	while (++i <= size)
	{
		if (ft_is_minb(pile, pa, 0, ft_2listhead(PILEB)->value)
				&& ft_set_values("pa\nra\n", 0))
		{
			ft_pusha(pile);
			PILEA = ft_2listrotate(PILEA);
			count++;
		}
		else if (PILEBVAL <= key && ft_set_values("rb\n", 0))
		{
			PILEB = ft_2listrotate(PILEB);
		}
		else if (ft_set_values("pa\n", 0) && ++pa)
			ft_pusha(pile);
	}
	return (count);
}

int		ft_reinit(t_2pile *pile, int len)
{
	int	j;

	j = 0;
	PILEA = ft_2listhead(PILEA);
	while (len--)
	{
		if (ft_is_min(pile, len, PILEAVAL)
				&& ft_set_values("ra\n", 0) && ((j += 1) + 1))
			PILEA = ft_2listrotate(PILEA);
		else if (ft_set_values("pb\n", 0))
			ft_pushb(pile);
	}
	return (j);
}

void	ft_2sortb(t_2pile *pile, int lenb, int *tab)
{
	int		len;
	int		lena;
	int		i;
	int		check;

	check = lenb;
	i = 0;
	lena = ft_2listsize(PILEA);
	len = ft_2listsize(ft_2listhead(PILEB));
	while (tab[i])
		i++;
	if (len > 3 && !ft_is_reverse(PILEB))
	{
		lenb -= ft_partitionb(pile, ft_find_pivot(PILEB, len, 2), len, 0);
		tab[i] = ft_2listsize(PILEA) - lena - check + lenb;
		ft_2sortb(pile, lenb, tab);
	}
	else
	{
		sort_small(pile, len);
		lenb -= len;
		ft_find_opti(lenb, pile, tab, i);
	}
}

void	quick2sort(t_2pile *pile, int key, int len)
{
	int lena;
	int lenb;
	int *tab;

	lena = ft_2listsize(PILEA);
	if (!(tab = malloc(sizeof(int) * lena)))
		ft_exit();
	ft_bzero(tab, lena);
	if (!key)
		key = ft_find_pivot(PILEA, len, 2);
	if (ft_is_finish(pile->pilea))
		return ;
	ft_partitiona(pile, key, len);
	lena = ft_2listsize(PILEA);
	lenb = ft_2listsize(PILEB);
	ft_2sortb(pile, lenb, tab);
	ft_reinit(pile, lena);
	ft_2sortb(pile, ft_2listsize(PILEB), tab);
	ft_memdel((void**)&tab);
}
