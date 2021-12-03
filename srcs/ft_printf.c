/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/03 10:00:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

static int	ft_gsd(char *s, va_list arg)
{
	t_flag	flag;

	flag = initflag();
	getflag1(&flag, s);
	getflag2(&flag, s);
	getarg(&flag, arg);
	cleanflag(&flag);
	createstr(&flag);
	if (flag.conv == 'c' && flag.arg == 0)
		ft_putnstrzero_fd(flag.str, 1, flag.lstr);
	else
		ft_putstr_fd(flag.str, 1);
	if (flag.str)
	{
		free(flag.str);
		flag.str = NULL;
	}
	return (flag.lstr);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	count;
	va_list			arg;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%' && s++)
		{
			count += ft_gsd((char *)s, arg);
			while (*s && ! ft_isarg(*s) && s++)
				;
		}
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		s++;
	}
	va_end(arg);
	return (count);
}
