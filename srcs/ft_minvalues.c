/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minvalues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 04:14:21 by allauren          #+#    #+#             */
/*   Updated: 2017/12/19 05:56:10 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_min(t_2pile *pile, int len, int value)
{
	int i;

	i = 0;
	PILEA = PILEANEX;
	while (i < len && PILEA->next)
	{
		if (PILEAVAL < value)
		{
			PILEA = ft_2listhead(PILEA);
			return (0);
		}
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

int		ft_is_minb(t_2pile *pile, int len, int i, int value)
{
	PILEB = ft_2listhead(PILEB);
	PILEA = ft_2listhead(PILEA);
	while (i < len && PILEA->next)
	{
		if (PILEAVAL < value)
			return (0);
		PILEA = PILEANEX;
		i++;
	}
	PILEA = ft_2listhead(PILEA);
	while (PILEB && ft_2listhead(PILEB)->next)
	{
		if (PILEBVAL < value)
		{
			PILEB = ft_2listhead(PILEB);
			return (0);
		}
		if (PILEBNEX)
			PILEB = PILEBNEX;
		else
			break ;
	}
	PILEB = ft_2listhead(PILEB);
	return (1);
}
