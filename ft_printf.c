/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 12:56:23 by fle-blay         ###   ########.fr       */
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
	//printflag(&flag);
	createstr(&flag);
	ft_putstr_fd(flag.str, 1);
	//printflag(&flag);
	//printf("\n");
	
	//destroy_struct TODO

//	return(ft_strlen(flag.str));
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
	/*printf("1return : %d\n",ft_printf("ma chaine % 12d continue%sEOF\n", 0, "LOL"));
	printf("2return : %d\n",printf("ma chaine % 12d continue%sEOF\n", 0, "LOL"));
	printf("3return : %d\n",ft_printf("ma chaine %+12d continue%sEOF\n", 88, "LOL"));
	printf("4return : %d\n",printf("ma chaine %+12d continue%sEOF\n", 88, "LOL"));
	printf("5return : %d\n",ft_printf("ma chaine %+12.4d continue%sEOF\n", 88, "LOL"));
	printf("6return : %d\n",printf("ma chaine %+12.4d continue%sEOF\n", 88, "LOL"));
	printf("7return : %d\n",ft_printf("ma chaine %+12.4d continue%sEOF\n", -88, "LOL"));
	printf("8return : %d\n",printf("ma chaine %+12.4d continue%sEOF\n", -88, "LOL"));
	printf("9return : %d\n",ft_printf("ma chaine %+.4d continue%sEOF\n", -88, "LOL"));
	printf("10return : %d\n",printf("ma chaine %+.4d continue%sEOF\n", -88, "LOL"));
	printf("11return : %d\n",ft_printf("ma chaine %012d continue%sEOF\n", -88, "LOL"));
	printf("12return : %d\n",printf("ma chaine %012d continue%sEOF\n", -88, "LOL"));
	printf("13return : %d\n",ft_printf("ma chaine %012.4d continue%sEOF\n", -88, "LOL"));
	printf("14return : %d\n",printf("ma chaine %012.4d continue%sEOF\n", -88, "LOL"));
	printf("15return : %d\n",ft_printf("ma chaine %12.4d continue%sEOF\n", -88, "LOL"));
	printf("16return : %d\n",printf("ma chaine %12.4d continue%sEOF\n", -88, "LOL"));
	printf("17return : %d\n",ft_printf("ma chaine %+05d continue%sEOF\n", 88, "LOL"));
	printf("18return : %d\n",printf("ma chaine %+05d continue%sEOF\n", 88, "LOL"));
	
	printf("19return : %d\n",ft_printf("ma chaine %#08.29X continueEOF\n", 8));
	printf("20return : %d\n",printf("ma chaine %#08.29X continueEOF\n", 8));
	printf("19bisreturn : %d\n",ft_printf("ma chaine %#08.29x continueEOF\n", 8));
	printf("20bisreturn : %d\n",printf("ma chaine %#08.29x continueEOF\n", 8));
	printf("19ter : %d\n",ft_printf("ma chaine %#08.29x continueEOF\n", -8));
	printf("20ter : %d\n",printf("ma chaine %#08.29x continueEOF\n", -8));
	printf("21return : %d\n",ft_printf("ma chaine %#08.X continueEOF\n", 8));
	printf("22return : %d\n",printf("ma chaine %#08.X continueEOF\n", 8));
	printf("21return : %d\n",ft_printf("ma chaine %#8.X continueEOF\n", 8));
	printf("22return : %d\n",printf("ma chaine %#8.X continueEOF\n", 8));
	printf("21return : %d\n",ft_printf("ma chaine %#8X continueEOF\n", 8));
	printf("22return : %d\n",printf("ma chaine %#8X continueEOF\n", 8));
	printf("21bisreturn : %d\n",ft_printf("ma chaine %08.X continueEOF\n", 8));
	printf("22bisreturn : %d\n",printf("ma chaine %08.X continueEOF\n", 8));
	printf("23return : %d\n",ft_printf("ma chaine %#-.X continueEOF\n", 8));
	printf("24return : %d\n",printf("ma chaine %#-.X continueEOF\n", 8));*/
	//printf("25return : %d\n",ft_printf("ma chaine %%"));
	//printf("26return : %d\n",printf("ma chaine %%"));
	//printf("27return : %d\n",ft_printf("ma chaine %p\n", "toto"));
	//printf("27return : %d\n",printf("ma chaine %p\n", "toto"));
	//printf("27return : %d\n",ft_printf("ma chaine %p\n", NULL));
	//printf("27return : %d\n",printf("ma chaine %p\n", NULL));
	//printf("6return : %d\n",printf("ma chaine %12.4u continue%sEOF\n", 88, "LOL"));
	//printf("7return : %d\n",ft_printf("ma chaine %12.4u continue%sEOF\n", 88, "LOL"));
	//printf("6return : %d\n",printf("ma chaine :%12.4s\n", "123456"));
	//printf("6return : %d\n",ft_printf("ma chaine :%12.4s\n", "123456"));
	//printf("6return : %d\n",printf("ma chaine :%12.0s\n", "123456"));
	//printf("6return : %d\n",ft_printf("ma chaine :%12.0s\n", "123456"));
	//printf("6return : %d\n",printf("ma chaine :%12.s\n", "123456"));
	//printf("6return : %d\n",ft_printf("ma chaine :%12.s\n", "123456"));
	//printf("6return : %d\n",printf("ma chaine :%12s\n", "123456"));
	//printf("6return : %d\n",ft_printf("ma chaine :%12s\n", "123456"));

	printf("6return : %d\n",printf("ma chaine :%12.c\n", 'a'));
	printf("6return : %d\n",ft_printf("ma chaine :%12.c\n", 'a'));
	printf("6return : %d\n",printf("ma chaine :%12c\n", 'a'));
	printf("6return : %d\n",ft_printf("ma chaine :%12c\n", 'a'));
	return (0);
}
