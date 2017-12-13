/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:35 by allauren          #+#    #+#             */
/*   Updated: 2017/12/13 14:12:56 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printdixtab(int *a)
{
	int j = -1;

	while(++j <= 8)
		ft_printf("tab[%d] =%5d\n", j, a[j]); 

}

int		ft_find_pivot(t_2pile *pile, int key)
{
	pile->pilea = ft_2listtail(pile->pilea);
	while (pile->pilea  && pile->pilea->head && pile->pilea->value > pile->pilea->head->value)
		pile->pilea = pile->pilea->head;
	if(pile->pilea)
	key = pile->pilea->value;
	return (key);
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

void		ft_partition(t_2pile *pile, int key)
{
	int		count_push = 0;

	pile->pilea = ft_2listhead(pile->pilea);
	while(pile->pilea->value != key)
	{
	//ft_print_pile(pile);
	if (pile->pilea->value < key && ft_set_values("pb\n", 0) && ++count_push)
		ft_pushb(pile);
	else if(ft_set_values("ra\n", 0))
		pile->pilea =ft_2listrotate(pile->pilea);
	}
	while (pile->pileb && ft_set_values("pa\n", 0))
		ft_pusha(pile);
}


void	quick2sort(t_2pile *pile,int key)
{

	if(ft_is_finish(pile->pilea))
		return;
	key = ft_find_pivot(pile, key);
//	key = 25;
//	ft_printf("pivot est %d\n", key);
	ft_partition(pile, key);
	pile->pilea = ft_2listhead(pile->pilea);
	quick2sort(pile, key);
	}

/*
void	quick2sort(int *a, int len)
{
	if(len < 2)
		return;
	int pivot;
	int j;
	int i;

	ft_print_pile(pile);
	ft_print_pile(pile);
	pivot = a[len / 2];
	int count = -1;
	//while(++count < (len - 1))
		//ft_printf("pushb");
		i = 0;
	j = len - 1;
	while (1)
	{
		while (a[i] < pivot) 
		{
			i++;
		}
			while (a[j] > pivot) 
			{
				j--;
			}
				if (i >= j) 
		break;
	ft_swap(a, i , j);
	}					 
	quick2sort(a, i);
	quick2sort(a + i, len - i);
}

int		main(int argc, const char *argv[])
{
	char	**ptr;
	int		tab[50000];
	int		i;

	ft_bzero(tab, 50000);
	i = -1;
	ptr = NULL;
	if (argc != 2)
	{
		ft_printf("les arguments debile");
		return (-1);
	}
	ptr = ft_strsplit(argv[1], ' ');
	while (ptr[++i])
		tab[i] = ft_atoi(ptr[i]);
	quick2sort(tab,i);
	int j = 0;
	while (j < i)
		ft_printf("sortie du quick2sort ==> %d\n", tab[j++]);
	return 0;
}*/
