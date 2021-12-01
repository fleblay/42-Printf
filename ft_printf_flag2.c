/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:47:42 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 14:28:16 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>

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
