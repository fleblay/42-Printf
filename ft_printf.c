/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/30 12:18:08 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

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

int	ft_gsd(char *s, va_list arg)
{
	t_flag	flag;
	
	flag = initflag();
	getflag1(&flag, s);
	getflag2(&flag, s, arg);
	cleanflag(&flag);
	createstr(&flag);
	ft_putstr_fd(flag.str, 1);
	//printflag(&flag);
	//printf("\n");
	
	//destroy_struct TODO

	return(flag.lstr);
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

int main(void)
{
	printf("return : %d\n",ft_printf("ma chaine %+-2.4d continue%sEOF\n", 88, "LOL"));
	printf("return : %d\n",printf("ma chaine %+-2.4d continue%sEOF\n", 88, "LOL"));
	//printf("return : %d\n",ft_printf("ma chaine %#+ -08.29X continueEOF\n", 8));
	//printf("return : %d\n",ft_printf("ma chaine %#+ -08.X continueEOF\n", 8));
	//printf("return : %d\n",ft_printf("ma chaine %#+ -.X continueEOF\n", 8));
	//printf("return : %d\n",ft_printf("ma\n"));
	//printf("return : %d\n",ft_printf("ma%d\n", 3));
	//printf("return : %d\n",ft_printf("ma%d\n", 32));
	//printf("return : %d\n",ft_printf("ma chaine %%"));
	//printf("return : %d\n",ft_printf("ma chaine %Z", 9));
	//printf("return : %d\n",printf("ma chaine %Z", 9));
	return (0);
}
