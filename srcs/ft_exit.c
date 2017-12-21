/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:25:21 by allauren          #+#    #+#             */
/*   Updated: 2017/12/21 16:23:53 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_exit(void)
{
	ft_alexis();
	exit(-1);
}

int			ft_return(char *str, char **p)
{
	ft_strdel(&str);
	free(p);
	return (0);
}

int			ft_check_option(t_2option *s, char **av)
{
	if (ft_strcmp(av[1], "-v"))
		return (1);
	s->v = 1;
	return (2);
}
