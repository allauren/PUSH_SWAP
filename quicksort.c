/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:35 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 20:14:35 by allauren         ###   ########.fr       */
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
	while (PILEB && ++i < size)
		if (PILEBVAL > key && ft_set_values("pa\n", 0))
			ft_pusha(pile);
		else if(ft_set_values("rb\n", 0))
			PILEB =ft_2listrotate(PILEB); 
	return (1);
}

void	ft_reinit(t_2pile *pile, int len)
{
	while (len-- && ft_set_values("pa\n", 0))
		ft_pushb(pile);
}

void	ft_2sortb(t_2pile *pile, int lenb)
{
	int		len;

	len = ft_2listsize(PILEB);
//	while(lenb)
//	{
	if(len > 4)
	{
		ft_partitionb (pile, ft_find_pivot(PILEB, len, 2), len);
		ft_2sortb(pile, lenb);
	}
	else
	{
		sort_small(pile, len);
		lenb -= len;
		ft_reinit(pile, lenb);
		//ft_print_pile(pile);
	//	ft_printf("\n\n%d\n", len);
	}
//	}
}

void	quick2sort(t_2pile *pile, int key,int len)
{
	int lena;
	int lenb;
	if (!key)
		key = ft_find_pivot(PILEA, len, 2);
	if(ft_is_finish(pile->pilea))
		return;
	ft_partitiona(pile, key, len);
	lena = ft_2listsize(PILEA);
	lenb = ft_2listsize(PILEB);
//	while (!ft_is_finish(PILEA) && PILEB)
//	{
	ft_2sortb(pile, lenb);





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

