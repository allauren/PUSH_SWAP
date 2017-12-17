/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:10:47 by allauren          #+#    #+#             */
/*   Updated: 2017/12/01 07:03:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_convert	set_struct(char c, int (*f)(va_list ap, t_option *s, t_size *l))
{
	t_convert s;

	s.c = c;
	s.f = f;
	return (s);
}

int			set_function(va_list ap, char c, t_option *s, t_size *l)
{
	t_convert	tab[16];
	int			i;

	i = 0;
	tab[0] = set_struct('s', printf_string);
	tab[1] = set_struct('d', printf_numbers);
	tab[2] = set_struct('D', printf_dnumbers);
	tab[3] = set_struct('i', printf_numbers);
	tab[4] = set_struct('u', printf_unumbers);
	tab[5] = set_struct('U', printf_umnumbers);
	tab[6] = set_struct('x', printf_hex);
	tab[7] = set_struct('X', printf_hexm);
	tab[8] = set_struct('o', printf_oct);
	tab[9] = set_struct('O', printf_octm);
	tab[10] = set_struct('%', printf_pourcent);
	tab[11] = set_struct('c', printf_char);
	tab[12] = set_struct('C', printf_wchar);
	tab[13] = set_struct('p', printf_p);
	tab[14] = set_struct('S', printf_wstr);
	tab[15] = set_struct('\0', NULL);
	while (i < 14 && tab[i].c != c)
		i++;
	return ((i < 15) ? tab[i].f(ap, s, l) : -1);
}

int			ft_parse(const char *format, va_list ap, int *ret)
{
	char		*option;
	t_option	s;
	t_size		l;
	t_init		p;

	ft_bzero(&p, sizeof(t_init));
	p.i += ft_bzero(&s, sizeof(t_option)) + ft_bzero(&l, sizeof(t_size));
	if (ft_stritostr(format, TYPE) != -1 && (s.pre = -1))
	{
		p.len = ft_stritostr(format, TYPE);
		option = ft_strsub(&format[p.i], p.i, p.len);
		p.i += ft_setoption(option, &s, &l);
		if (s.moins)
			s.zero = 0;
		if (s.plus)
			s.space = 0;
		p.j = *ret;
		*ret += set_function(ap, format[p.len], &s, &l);
		ft_memdel((void**)&option);
		if (p.j > *ret)
			*ret = -1;
		return (p.i + 1);
	}
	*ret = -1;
	return (0);
}
