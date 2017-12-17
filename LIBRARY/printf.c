/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:04 by allauren          #+#    #+#             */
/*   Updated: 2017/12/01 08:27:53 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_runthrough(char *format, va_list ap, t_decla s, int ret)
{
	while (format[s.i])
	{
		if (format[s.i] == '%' && format[s.i + 1])
		{
			if (s.j - s.i++ != 0)
			{
				printf_to_limit(&format[s.j], (s.i - s.j) - 1);
				ret += (s.i - s.j - 1);
			}
			s.i += ft_parse(&format[s.i], ap, &ret);
			if (ret == -1)
				return (-1);
			s.j = s.i;
		}
		else
			s.i++;
	}
	if (format[s.j] && format[s.j] != '%')
	{
		ret += (s.i - s.j);
		ft_putstr(&format[s.j]);
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;
	t_decla	s;

	ft_bzero(&s, sizeof(t_decla));
	ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	if (((ret = ft_runthrough((char*)format, ap, s, ret)) == -1))
		return (-1);
	va_end(ap);
	return (ret);
}
