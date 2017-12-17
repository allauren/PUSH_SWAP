/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilspsw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:02:40 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 00:50:56 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2list		*ft_fill(t_2list *pilea, int *tab, int i)
{
	int		j;

	j = -1;
	while (++j < i)
	{
		pilea = ft_2listfront(pilea, ft_2list_new(tab[j], j + 1));
	}
	return (pilea);
}

int			ft_cut(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**pab;

	pab = NULL;
	i = ac;
	j = 0;
	while (--i >= 1 && ((k = 0) + 1))
	{
		if (!(pab = ft_strsplit(av[i], ' ')))
		{
			ft_exit();
		}
		while (pab[k])
		{
			ft_memdel((void**)&pab[k]);
			k++;
			j++;
		}
		free(pab);
		pab = NULL;
	}
	return (j);
}

int			ft_is_redundant(char *str1, char **tab)
{
	int i;
	int count;
	int token;

	i = 0;
	token = 0;
	count = 0;
	while (tab[i] && str1 == tab[i])
	{
		count++;
		i++;
	}
	count = count + i;
	while (tab[i] && str1[0] == tab[i][0] && str1[1] != tab[i][1] && i < count)
	{
		i++;
		token = 1;
	}
	if (token)
		return (i);
	else
		return (0);
}

char		*ft_realloc(char *str, int size)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_memalloc(size + 1)))
		ft_exit();
	if (tmp)
	{
		str = ft_strcat(str, tmp);
		ft_strdel(&tmp);
	}
	return (str);
}

int			ft_set_values(char *ptr, int taille)
{
	static char	*str = NULL;
	static int	i = 1;
	int			len;

	if (taille > 0)
	{
		str = ft_short_string(str, taille, str);
		return (1);
	}
	len = str ? ft_strlen(str) : 1;
	if ((!str && taille != -1) || (i * 4096 - len < 5))
		str = ft_realloc(str, ++i * 4096);
	if (ptr)
		ft_strcat(str, ptr);
	else
	{
		ft_printf("%s", str);
		ft_strdel(&str);
	}
	return (1);
}
