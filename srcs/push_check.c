/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:30:42 by allauren          #+#    #+#             */
/*   Updated: 2017/12/18 21:47:18 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_cleanstr(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(ft_strlen(str) + 1)) && ft_memdel((void**)&str))
		ft_exit();
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	ft_strcat(ret, &str[i]);
	ft_strdel(&str);
	return (ret);
}

int			ft_checker(int i, char **argv, int *tab)
{
	int		j;
	int		k;
	char	**pab;

	j = 0;
	while (--i >= 1 && ((pab = NULL) + 1))
	{
		if (((k = 0) + 1)
				&& !(pab = ft_strsplit(argv[i], ' ')))
			ft_exit();
		while (pab[k])
			k++;
		while (--k > -1)
		{
			if (!(tab[j] = ft_atoi(pab[k])) && !ft_fullzero(pab[k]))
				return (ft_return(pab[k], pab));
			if (!ft_ispresent(tab, j) || ft_atoi(pab[k]) > 2147483647
					|| ft_atoi(pab[k]) < -2147483648 || (tab[j] && pab[k]
					&& ft_strlen((pab[k] = ft_cleanstr(pab[k]))) > 10))
				return (ft_return(pab[k], pab));
			j += 1 + ft_memdel((void**)&pab[k]);
		}
		free(pab);
	}
	return (1);
}

void		ft_print_pile(t_2list *pilea, t_2list *pileb, int i)
{
	if (!i)
	ft_printf("   PILEA    \t   PILEB   \n");
	if (!pileb && !pilea)
		ft_printf("         FIN DES PILES        ");
	if (pilea) 
		ft_printf("%6d\t", pilea->value);
	else
		ft_printf("           " );
	if (pileb) 
		ft_printf("\t%6d\n", pileb->value);
	else 
		ft_printf("\t\t           \n" );
	if (pileb && pileb->next && pilea && pilea->next)
		ft_print_pile(pilea->next, pileb->next, 1);
	else if (pileb && pileb->next)
		ft_print_pile(NULL, pileb->next, 1);
	else if (pilea && pilea->next)
		ft_print_pile(pilea->next, NULL, 1);
}

t_2pile		*ft_orders(char *line, t_2pile *pile)
{
	if ((!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss")))
		PILEA = PILEA ? ft_swap(PILEA, PILEANEX) : NULL;
	else if ((!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss")))
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
	{
		ft_2lstdelall(PILEA);
		ft_2lstdelall(PILEB);
		exit(-1);
	}
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
