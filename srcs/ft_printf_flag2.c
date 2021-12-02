/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:47:42 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/02 13:11:23 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

#include <stdio.h>

/*
void	printflag(t_flag *flag)
{
	printf("dash : %d\n", flag->dash);
	printf("zero : %d\n", flag->zero);
	printf("dot : %d\n", flag->dot);
	printf("dotn : %d\n", flag->dotn);
	printf("mfw : %d\n", flag->mfw);
	printf("bang : %d\n", flag->bang);
	printf("space : %d\n", flag->spce);
	printf("plus : %d\n", flag->plus);
	printf("conv : %c\n", flag->conv);
	printf("lstr : %d\n", flag->lstr);
	printf("str : %s\n", flag->str);
	printf("arg : %lld\n", flag->arg);
	printf("minus : %d\n", flag->minus);
}
*/

void	getarg(t_flag *flag, va_list arg)
{
	char	*tmp;

	tmp = NULL;
	if (flag->conv == 'p')
		flag->arg = va_arg(arg, unsigned long long);
	else if (flag->conv == 'u')
		{
		flag->arg = va_arg(arg, unsigned int);
		//printf("arga : %u\n", (unsigned int)flag->arg);
		}
	else if (flag->conv == 's')
	{
		tmp = va_arg(arg, char *);
		if (tmp)
			flag->str = ft_strdup(tmp);
		else
			flag->str = ft_strdup("(null)");
	}
	else if(flag->conv != '%')
	{
		flag->arg = (int)va_arg(arg, long long);
		if (flag->arg < 0)
			flag->minus = 1;
	}
}

void	cleanflag(t_flag *flag)
{
	if (flag->dash == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->dot == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->plus == 1 && flag->spce == 1)
		flag->spce = 0;
	if (flag->bang == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->minus == 1 && flag->spce == 1)
		flag->spce = 0;
	if (flag->minus == 1 && flag->plus == 1)
		flag->plus = 0;
}

char	*chartostr(char c)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup("a");
	if (tmp)
		tmp[0] = c;
	return (tmp);
}

//TODO : Destroy structflag !
