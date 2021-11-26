/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/26 18:11:13 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_isarg(char c)
{
	int i;
	static char	*arg = "cspdiuxX%";

	i = 0;
	while (i < 9)
	{
		if (c == arg[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_gsd(const char *s, va_list arg)
{
	/* substr de s jusqu'a fin arg qu'on envoie a la bonne fx. Penser a free*/
	/* Penser a ce que la fx return le nombre de char ecrits !*/
	while (*s && !ft_isarg(*s) && s++);
	if (*s && *s == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1);
	return (1);
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
			count += ft_gsd(s, arg);
			while (*s && ! ft_isarg(*s) && s++); // Je vais jusqu'au prochain arg
		}
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		s++; // si j'etais sur un arg, je suis sur le char apres le prochain arg
	}
	va_end(arg);
	return (count);
}

#include <stdio.h>
int main(void)
{
	printf("return : %d\n",ft_printf("ma chaine % 8d continue %sEOF\n", 9, 1));
	printf("return : %d\n",ft_printf("ma\n"));
	printf("return : %d\n",ft_printf("ma%d\n", 3));
	printf("return : %d\n",ft_printf("ma%d\n", 32));
	printf("return : %d\n",ft_printf("ma chaine %%"));
	printf("return : %d\n",ft_printf("ma chaine %Z", 9));
	printf("return : %d\n",printf("ma chaine %Z", 9));
	return (0);
}
