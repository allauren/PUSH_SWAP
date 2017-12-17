/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:30:42 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 04:08:55 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_ispresent(int *tab, int i)
{
	int j;
	int c;

	c = tab[i];
	j = i;
	while (--j > -1)
	{
		if (tab[j] == c)
			return (0);
	}
	return (1);
}

int		ft_fullzero(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] != '0')
			return (0);
	return (1);
}

char	*ft_cleanstr(char* str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(ft_strlen(str) + 1)))
		ft_exit();
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	ft_strcat(ret, &str[i]);
	ft_strdel(&str);
	return (ret);
}

//void	ft_checkvalvalid(

int			ft_checker(int i, char **argv, int *tab)
{
	int		j;
	int		k;
	char	**pab;
	j = 0;
	while (--i >= 1 && ((pab = NULL) + 1))
	{
		if (((k = 0) + 1) && !(pab = ft_strsplit(argv[i], ' ')))
			ft_exit();
		while (pab[k])
			k++;
		while (--k > -1)
		{
			if (!(tab[j] = ft_atoi(pab[k])) && !ft_fullzero(pab[k]))
				return (0);
			if (!ft_ispresent(tab, j)
					|| ft_atoi(pab[k]) > 2147483647
					|| ft_atoi(pab[k]) < -2147483648
					|| (tab[j] && pab[k]
					&& ft_strlen((pab[k] = ft_cleanstr(pab[k]))) > 10))
				return (0);
			j += 1 + ft_memdel((void**)&pab[k]);
		}
		free(pab);
	}
	return (1);
}

void		ft_print_pile(t_2pile *pile)
{
	pile->pilea = ft_2listhead(pile->pilea);
	pile->pileb = ft_2listhead(pile->pileb);
	ft_printf("PILEA\n");
	while (pile->pilea)
	{
		ft_printf("%d\n", pile->pilea->value);
		if (pile->pilea->next)
			pile->pilea = pile->pilea->next;
		else
			break ;
	}
	ft_printf("PILEB\n");
	while (pile->pileb)
	{
		ft_printf("%d\n", pile->pileb->value);
		if (pile->pileb->next)
			pile->pileb = pile->pileb->next;
		else
			break ;
	}
	pile->pilea = ft_2listhead(pile->pilea);
	pile->pileb = ft_2listhead(pile->pileb);
}

t_2pile		*ft_orders(char *line, t_2pile *pile)
{
	if ((!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss")))
		PILEA = PILEA ? ft_swap(PILEA, PILEANEX) : NULL;
	else if ((!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss")) )
		PILEB = PILEB ? ft_swap(PILEB, PILEBNEX) : NULL;
	else if (!ft_strcmp(line, "pa"))
		ft_pusha(pile);
	else if (!ft_strcmp(line, "pb"))
		ft_pushb(pile);
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
		pile->pilea = ft_2listrotate(pile->pilea);
	else if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		pile->pileb = ft_2listrotate(pile->pileb);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		pile->pilea = ft_2listrevrotate(pile->pilea);
	else if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		pile->pileb = ft_2listrevrotate(pile->pileb);
	else if (ft_printf("Error\n") && !ft_memdel((void**)&line))
		exit (-1);
	return (pile);
}

void		ft_readpsw(t_2pile *pile)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		pile = ft_orders(line, pile);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	if (!pile->pileb)
		ft_is_sort(pile->pilea);
	else
		ft_printf("KO\n");
}
