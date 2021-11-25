/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/25 19:12:32 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
}

int	ft_gsd(const char *s, va_list arg)
{
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
			while (*s && ! ft_isarg(*s) && s++);
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

#include <stdio.h>
int main(void)
{
	printf("return : %d\n",ft_printf("ma chaine % 8d continue %sEOF\n", 9, 1));
	printf("return : %d\n",ft_printf("ma\n"));
	printf("return : %d\n",ft_printf("ma%d\n", 3));
	printf("return : %d\n",ft_printf("ma%d\n", 32));
	//printf("return : %d\n",ft_printf("ma chaine %%"));
	return (0);
}
