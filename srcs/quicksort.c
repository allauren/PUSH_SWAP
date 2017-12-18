/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:35 by allauren          #+#    #+#             */
/*   Updated: 2017/12/18 15:08:45 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_partitiona(t_2pile *pile, int key, int size)
{
	int		i;

	i = -1;
	PILEA = ft_2listhead(PILEA);
	while (PILEA && ++i < size)
		if (PILEAVAL < key && ft_set_values("pb\n", 0))
			ft_pushb(pile);
		else if (ft_set_values("ra\n", 0))
			PILEA = ft_2listrotate(PILEA);
	return (key);
}

int		ft_is_minb(t_2pile *pile)
{
	int value;

	value = ft_2listhead(PILEB)->value;
	while (PILEB)
	{
		if (PILEBVAL < value)
			return (0);
		if (PILEBNEX)
		PILEB = PILEBNEX;
		else
			break ;
	}
	return (1);
}

int		ft_partitionb(t_2pile *pile, int key, int size)
{
	int		i;

	i = -1;
	PILEB = ft_2listhead(PILEB);
	while (++i < size && PILEB)
		if (PILEBVAL > key && ft_set_values("pa\n", 0))
			ft_pusha(pile);
		else if (/*!ft_is_minb(pile) &&*/ ft_set_values("rb\n", 0))
			PILEB = ft_2listrotate(PILEB);
		else if (ft_set_values("pa\nra\n", 0))
				{
					ft_pusha(pile);
					PILEA = ft_2listrotate(PILEA);
				}
	return (i);
}

int		ft_is_min(t_2pile *pile, int len, int value)
{
	int i;

	i = 0;
//	ft_printf("len est %d\n", len);
	PILEA = PILEANEX;
	while (i < len && PILEA->next)
	{
		if (PILEAVAL < value)
			return(0);
		PILEA = PILEANEX;
		i++;
	}
	while (PILEB)
	{
		if (PILEBVAL < value)
			return (0);
		if (PILEBNEX)
		PILEB = PILEBNEX;
		else
			break ;
	}
	PILEB = ft_2listhead(PILEB);
	PILEA = ft_2listhead(PILEA);
	return (1);
}

int		ft_reinit(t_2pile *pile, int len)
{
	int	j;

	j = 0;
	PILEA = ft_2listhead(PILEA);
//	ft_print_pile(PILEA, PILEB, 0);
	while (len--)
	{
		if (ft_is_min(pile, len, PILEAVAL)
				&& ft_set_values("ra\n", 0) && ((j += 1) + 1))
			PILEA = ft_2listrotate(PILEA);
		else if(ft_set_values("pb\n", 0))
			ft_pushb(pile);
	}
		//	ft_printf("apres le push\n");
	//		ft_print_pile(PILEA, PILEB, 0);
	return(j);
}

void	ft_2sortb(t_2pile *pile, int lenb, int *tab)
{
	int		len;
	int		lena;
	int		i;

	i = 0;
	lena = ft_2listsize(PILEA);
	len = ft_2listsize(PILEB);
	while (tab[i])
		i++;
	if (len > 3 && !ft_is_reverse(PILEB))
	{
		ft_partitionb(pile, ft_find_pivot(PILEB, len, 2), len);
		tab[i] = ft_2listsize(PILEA) - lena;
		ft_2sortb(pile, lenb, tab);
	}
	else
	{
		sort_small(pile, len);
		lenb -= len;
//		ft_printf("avant le push\n");
//		ft_print_pile(PILEA, PILEB, 0);
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
//	ft_print_pile(PILEA, PILEB, 0);
	lena = ft_2listsize(PILEA);
	lenb = ft_2listsize(PILEB);
	ft_2sortb(pile, lenb, tab);
	ft_reinit(pile, lena);
	ft_2sortb(pile, ft_2listsize(PILEB), tab);
	ft_memdel((void**)&tab);
}
