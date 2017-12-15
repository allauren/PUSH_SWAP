/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:35 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 05:29:18 by allauren         ###   ########.fr       */
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
		else if(ft_set_values("ra\n", 0))
			PILEA =ft_2listrotate(PILEA); 
	return (key);
}

int		ft_partitionb(t_2pile *pile, int key, int size)
{
	int		i;

	i = -1;
	PILEB = ft_2listhead(PILEB);
	while (++i < size && PILEB)
		if (PILEBVAL > key && ft_set_values("pa\n", 0))
			ft_pusha(pile);
		else if(ft_set_values("rb\n", 0))
			PILEB = ft_2listrotate(PILEB); 
	return (i);
}

void	ft_reinit(t_2pile *pile, int len)
{
	while (len-- && ft_set_values("pb\n", 0))
		ft_pushb(pile);
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
	//ft_printf("len est %d\n", *lenb);
	//ft_print_pile(pile);
	while(PILEB && PILEBNEX && i < 3 && ft_is_smallest(PILEB))
	{
		PILEB = PILEBNEX;
		i++;
	}
	PILEB = ft_2listhead(PILEB);
	sort_small(pile, i);
	//ft_print_pile(pile);
	*lenb -= i;
	//ft_printf("len est %d\n", *lenb);
	return(pile);
}
*/

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
	if(len > 3 && !ft_is_reverse(PILEB))
	{
	//ft_print_pile(pile);
		ft_partitionb (pile, ft_find_pivot(PILEB, len, 2), len);
		tab[i] = ft_2listsize(PILEA) - lena;
	//	ft_printf("len est %d\n", tab[i]);
		//ft_print_pile(pile);
	//	pile = ft_is_opti(pile, &lenb);
		ft_2sortb(pile, lenb, tab);
	}
	else
	{
	//ft_print_pile(pile);
		sort_small(pile, len);
		lenb -= len;
//		ft_printf("len est %d\n", tab[i - 1]);

		ft_reinit(pile, tab[i - 1]);
		tab[i - 1] = 0;
	//ft_print_pile(pile);
		if (lenb)
		ft_2sortb(pile, lenb, tab);
	}
}

void	quick2sort(t_2pile *pile, int key,int len)
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
	if(ft_is_finish(pile->pilea))
		return;
	ft_partitiona(pile, key, len);
	lena = ft_2listsize(PILEA);
	lenb = ft_2listsize(PILEB);
	ft_2sortb(pile, lenb, tab);
	ft_reinit(pile, lena);
	ft_2sortb(pile, lena, tab);
//	ft_print_pile(pile);





//	}
	//	key = ft_find_pivot(pile, key);
	//	key = 25;
	//	ft_printf("pivot est %d\n", key);
	//	ft_partition(pile, key);
	//	pile->pilea = ft_2listhead(pile->pilea);
	//	quick2sort(pile, key);
}
int	ft_is_finish(t_2list *pilea)
{
	int		temp;

	while (pilea && pilea->next)
	{
		temp = pilea->value;
		if(pilea->next)
		{
			pilea = pilea->next;
			if (temp > pilea->value)
			{
				return (0);
			}
		}
		else
			break;
	}
	return (1);
}

