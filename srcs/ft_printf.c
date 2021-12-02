/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/02 12:52:33 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_isarg(char c)
{
	int			i;
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

/* Ajouter un destroy struct flag ?*/

int	ft_gsd(char *s, va_list arg)
{
	t_flag	flag;

	flag = initflag();
	getflag1(&flag, s);
	getflag2(&flag, s);
	getarg(&flag, arg);
	cleanflag(&flag);
	createstr(&flag);
	//check non printable ???
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
/*
#include <stdio.h>
int main(void)
{
	printf("1return : %d\n",ft_printf("ch % 12d continue%sEOF\n", 0, "LOL"));
	printf("2return : %d\n",printf("ch % 12d continue%sEOF\n", 0, "LOL"));
	printf("3return : %d\n",ft_printf("ch %+12d continue%sEOF\n", 88, "LOL"));
	printf("4return : %d\n",printf("ch %+12d continue%sEOF\n", 88, "LOL"));
	printf("5return : %d\n",ft_printf("ch %+12.4d continue%sEOF\n", 88, "LOL"));
	printf("6return : %d\n",printf("ch %+12.4d continue%sEOF\n", 88, "LOL"));
	printf("7return : %d\n",ft_printf("ch %+12.4d continue%sEOF\n", -88, "LOL"));
	printf("8return : %d\n",printf("ch %+12.4d continue%sEOF\n", -88, "LOL"));
	printf("9return : %d\n",ft_printf("ch %+.4d continue%sEOF\n", -88, "LOL"));
	printf("10return : %d\n",printf("ch %+.4d continue%sEOF\n", -88, "LOL"));
	printf("11return : %d\n",ft_printf("ch %012d continue%sEOF\n", -88, "LOL"));
	printf("12return : %d\n",printf("ch %012d continue%sEOF\n", -88, "LOL"));
	printf("13return : %d\n",ft_printf("ch %012.4d continue%sEOF\n", -88, "LOL"));
	printf("14return : %d\n",printf("ch %012.4d continue%sEOF\n", -88, "LOL"));
	printf("15return : %d\n",ft_printf("ch %12.4d continue%sEOF\n", -88, "LOL"));
	printf("16return : %d\n",printf("ch %12.4d continue%sEOF\n", -88, "LOL"));
	printf("17return : %d\n",ft_printf("ch %+05d continue%sEOF\n", 88, "LOL"));
	printf("18return : %d\n",printf("ch %+05d continue%sEOF\n", 88, "LOL"));
	
	printf("19return : %d\n",ft_printf("ch %#08.29X continueEOF\n", 8));
	printf("20return : %d\n",printf("ch %#08.29X continueEOF\n", 8));
	printf("19bisreturn : %d\n",ft_printf("ch %#08.29x continueEOF\n", 8));
	printf("20bisreturn : %d\n",printf("ch %#08.29x continueEOF\n", 8));
	printf("19ter : %d\n",ft_printf("ch %#08.29x continueEOF\n", -8));
	printf("20ter : %d\n",printf("ch %#08.29x continueEOF\n", -8));
	printf("21return : %d\n",ft_printf("ch %#08.X continueEOF\n", 8));
	printf("22return : %d\n",printf("ch %#08.X continueEOF\n", 8));
	printf("21return : %d\n",ft_printf("ch %#8.X continueEOF\n", 8));
	printf("22return : %d\n",printf("ch %#8.X continueEOF\n", 8));
	printf("21return : %d\n",ft_printf("ch %#8X continueEOF\n", 8));
	printf("22return : %d\n",printf("ch %#8X continueEOF\n", 8));
	printf("21bisreturn : %d\n",ft_printf("ch %08.X continueEOF\n", 8));
	printf("22bisreturn : %d\n",printf("ch %08.X continueEOF\n", 8));
	printf("23return : %d\n",ft_printf("ch %#-.X continueEOF\n", 8));
	printf("24return : %d\n",printf("ch %#-.X continueEOF\n", 8));
	printf("25return : %d\n",ft_printf("ch %%"));
	printf("26return : %d\n",printf("ch %%"));
	printf("27return : %d\n",ft_printf("ch %p\n", "toto"));
	printf("27return : %d\n",printf("ch %p\n", "toto"));
	printf("27return : %d\n",ft_printf("ch %p\n", NULL));
	printf("27return : %d\n",printf("ch %p\n", NULL));
	printf("6return : %d\n",printf("ch %12.4u continue%sEOF\n", 88, "LOL"));
	printf("7return : %d\n",ft_printf("ch %12.4u continue%sEOF\n", 88, "LOL"));
	printf("6return : %d\n",printf("ch :%12.4s\n", "123456"));
	printf("6return : %d\n",ft_printf("ch :%12.4s\n", "123456"));
	printf("6return : %d\n",printf("ch :%12.0s\n", "123456"));
	printf("6return : %d\n",ft_printf("ch :%12.0s\n", "123456"));
	printf("6return : %d\n",printf("ch :%12.s\n", "123456"));
	printf("6return : %d\n",ft_printf("ch :%12.s\n", "123456"));
	printf("6return : %d\n",printf("ch :%12s\n", "123456"));
	printf("6return : %d\n",ft_printf("ch :%12s\n", "123456"));

	printf("6return : %d\n",printf("ch :%12.c\n", 'a'));
	printf("6return : %d\n",ft_printf("ch :%12.c\n", 'a'));
	printf("6return : %d\n",printf("ch :%12c\n", 'a'));
	printf("6return : %d\n",ft_printf("ch :%12c\n", 'a'));
	while (1);
	return (0);
}
*/
