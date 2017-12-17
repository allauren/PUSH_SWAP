/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_charmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:49:07 by allauren          #+#    #+#             */
/*   Updated: 2017/12/01 09:25:35 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			wcharlen(unsigned int c)
{
	if (c <= 0x7f && (MB_CUR_MAX = 1))
		return (1);
	if (c <= 0x7ff && (MB_CUR_MAX = 2))
		return (2);
	if (c <= 0xffff && (MB_CUR_MAX = 3))
		return (3);
	else
	{
		MB_CUR_MAX = 4;
		return (4);
	}
}

char		*fill_tab(char *str, wint_t c)
{
	if (!(str = ft_memalloc(sizeof(char) * 5)))
		exit(-1);
	str[wcharlen(c)] = '\0';
	if (c <= 0x7f)
		str[0] = c;
	else if (c <= 0x7ff)
	{
		str[0] = 0b11000000 | ((c >> 6) & 0b00011111);
		str[1] = 0b10000000 | (c & 0b00111111);
	}
	else if (c <= 0xffff)
	{
		str[0] = 0b11100000 | ((c >> 12) & 0b00001111);
		str[1] = 0b10000000 | ((c >> 6) & 0b00111111);
		str[2] = 0b10000000 | (c & 0b00111111);
	}
	else
	{
		str[0] = 0b11110000 | ((c >> 18) & 0b00000111);
		str[1] = 0b10000000 | ((c >> 12) & 0b00111111);
		str[2] = 0b10000000 | ((c >> 6) & 0b00111111);
		str[3] = 0b10000000 | (c & 0b00111111);
	}
	return (str);
}

/*
** does the comparison on the fitting byte to calcul unicode
*/

int			ft_is_valid(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 127) || (MB_CUR_MAX == 2 && c > 2047)
			|| (MB_CUR_MAX == 3 && c > 65535)
			|| (MB_CUR_MAX == 4 && c > 2097151) || c > 0x10fff)
		return (0);
	return (1);
}
