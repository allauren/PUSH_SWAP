/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:07:53 by allauren          #+#    #+#             */
/*   Updated: 2017/12/13 14:14:51 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 *insertion_sort avec un temps execution de ??
 */
void		insertion_sort(t_2pile *pile, int taille)
{
	(void) taille;
	int	count_push = 0;
	int	count_rotate = 0;
	int	key = 0;
	t_2list	*temp;

	pile->pilea = ft_2listhead(pile->pilea);
	temp = pile->pilea->next;
	while (temp)
	{
		pile->pilea = ft_2listhead(pile->pilea);
		key = temp->value;
		temp = temp->next;
		while(pile->pilea->value != key)
		{
			if (pile->pilea->value < key && ++count_rotate && ft_set_values("ra\n", 0))
				pile->pilea = ft_2listrotate(pile->pilea);
			else if(++count_push && ft_set_values("pb\n", 0))
				ft_pushb(pile);
		}
		if (count_push && ++count_rotate && ft_set_values("ra\n", 0))
			pile->pilea = ft_2listrotate(pile->pilea);
		while (count_push && ft_set_values("pa\n", 0))
		{
			ft_pusha(pile);
			count_push--;
		}
		while(count_rotate && ft_set_values("rra\n", 0))
		{
			pile->pilea = ft_2listrevrotate(pile->pilea);
			count_rotate--;
		}
	}
}

void merge(int *a, int n, int m) 
{
	int	i;
	int	j;
	int	k;
	int *x = malloc(n * sizeof (int));

	i = 0;
	j= m;
	k = -1;
	while(++k < n)
	{
		if (j == n)
			x[k] = a[i++];
		else if(i == m)
			x[k] = a[j++];
		else if(a[j] < a[i])
			x[k] = a[j++];
		else
			x[k] = a[i++];
	}
	i = -1;
	while (++i < n)
		a[i] = x[i];
	free(x);
}

void merge2sort (int *a, int n)
{
	if (n < 2)
		return;
	int m = n / 2;
	merge2sort(a, m);
	merge2sort(a + m, n - m);
	merge(a, n, m);
}
