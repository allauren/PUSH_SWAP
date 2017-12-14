/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechpushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:55:58 by allauren          #+#    #+#             */
/*   Updated: 2017/12/14 17:56:38 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
