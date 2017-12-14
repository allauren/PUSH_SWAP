/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:07:53 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 17:54:50 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 *insertion_sort avec un temps execution de ??
 */
 
int		ft_count_index(t_2list *pilea, int value)
{
	int count = 0;

	pilea = ft_2listhead(pilea);
	while(pilea->value != value && ++count)
		pilea = pilea->next;
	return(count);
}


t_2pile	*ft_place_value(t_2pile *pile, int key, int taille)
{
	int		index;

	index = ft_count_index(PILEA, key);
	ft_printf("index %d \n", key);
	PILEA = ft_2listhead(PILEA);
	if (index > taille / 2)
	{
		ft_printf("revrotate");
		while (PILEAVAL != key && ft_set_values("rra\n", 0))
			PILEA = ft_2listrevrotate(PILEA);
	ft_print_pile(pile);
		ft_set_values("sa\n", 0);
		ft_swap(PILEA, PILEANEX);
	}
	else 
	{
		while (PILEAVAL != key && ft_set_values("ra\n", 0))
			PILEA = ft_2listrotate(PILEA);
		ft_set_values("sa\n", 0);
		ft_swap(PILEA, PILEANEX);
	}
	return(pile);
}

void		insertion_sort(t_2pile *pile, int taille)
{
	int key;

	while(!ft_is_finish(PILEA))
	{
//	ft_print_pile(pile);
		while(PILEAINF && PILEANEX)
			PILEA = PILEANEX;
		key = PILEAVAL;
		pile = ft_place_value(pile, key, taille);
		//ft_print_pile(pile);
		while(ft_2listhead(PILEA)->value > ft_2listtail(PILEA)->value
				&& ft_set_values("rra\n", 0))
			PILEA = ft_2listrevrotate(PILEA);
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
