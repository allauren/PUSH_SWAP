/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilpresort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:07:17 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 02:46:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printdixtab(int *a)
{
	int j;

	j = -1;
	while (++j <= 8)
		ft_printf("tab[%d] =%5d\n", j, a[j]);
}

int		*ft_concattab(int *tab, t_2list *pile)
{
	int i;

	i = 0;
	while (pile)
	{
		tab[i++] = pile->value;
		pile = pile->next;
	}
	return (tab);
}

int		*ft_insertformed(int *tab, int len)
{
	int j;
	int i;
	int key;

	j = 1;
	while (j < len)
	{
		key = tab[j];
		i = j - 1;
		while (i > -1 && tab[i] > key)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = key;
		j++;
	}
	return (tab);
}

int		ft_find_pivot(t_2list *pile, int len, int div)
{
	int key;
	int	*tab;

	if (!(tab = malloc((len + 1) * sizeof(int))))
		ft_exit();
	tab = ft_concattab(tab, pile);
	tab = ft_insertformed(tab, len);
	key = tab[len / div];
	ft_memdel((void**)&tab);
	return (key);
}
