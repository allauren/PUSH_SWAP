/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:12:55 by allauren          #+#    #+#             */
/*   Updated: 2017/12/01 07:11:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_wchar(va_list ap, t_option *s, t_size *l)
{
	wchar_t		c;
	char		*str;
	int			len;

	(void)l;
	str = NULL;
	c = va_arg(ap, wchar_t);
	str = fill_tab(str, c);
	if (!str)
		str = ft_null(str);
	len = wcharlen(c);
	if (!ft_is_valid(c))
	{
		free(str);
		return (-1);
	}
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		ft_wstrlen(wchar_t *str)
{
	int		j;
	int		i;
	int		len;

	j = 0;
	i = -1;
	while (str[++i])
	{
		j += (len = wcharlen(str[i]));
		if (!ft_is_valid(str[i]))
			return (-1);
	}
	return (j);
}

int		ft_lenwstr(wchar_t *ptr, char *str, t_option *s)
{
	int		i;
	int		j;
	int		z;
	int		ret;

	i = 0;
	j = 0;
	z = 0;
	ret = 0;
	while (s->pre != -1 && s->pre < (int)ft_strlen(str) && str[i])
	{
		j += wcharlen(ptr[z]);
		while (i < j && i < s->pre && str[i])
			i++;
		if (i == j)
			ret = i;
		if (i == s->pre || !str[i])
			return (ret);
		z++;
	}
	return (ft_strlen(str));
}

int		printf_wstr(va_list ap, t_option *s, t_size *l)
{
	wchar_t		*ptr;
	char		*str;
	int			len;
	int			i;
	char		*prov;

	(void)l;
	i = -1;
	if (!(ptr = va_arg(ap, wchar_t*)))
		ptr = L"(null)";
	if ((len = ft_wstrlen(ptr)) == -1)
		return (-1);
	if (!(str = ft_memalloc(sizeof(char) * (len + 1))))
		exit(-1);
	while (ptr[++i])
	{
		prov = fill_tab(NULL, ptr[i]);
		ft_strcat(str, prov);
		free(prov);
	}
	len = ft_lenwstr(ptr, str, s);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}
