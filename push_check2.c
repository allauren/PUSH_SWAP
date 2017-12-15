/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 07:10:01 by allauren          #+#    #+#             */
/*   Updated: 2017/12/15 17:46:22 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void		ft_exit(void)
{
	ft_alexis();
	exit(-1);
}

void		ft_is_sort(t_2list *pilea)
{
	int		temp;

	while (pilea && pilea->next)
	{
		temp = pilea->value;
		if (pilea->next)
		{
			pilea = pilea->next;
			if (temp > pilea->value)
			{
				ft_printf("KO\n");
				return ;
			}
		}
		else
			break ;
	}
	ft_printf("OK\n");
}


