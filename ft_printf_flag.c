/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:52:54 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/29 18:41:29 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>

#include <stdio.h>

t_flag	initflag(void)
{
	t_flag	flag;

	flag.dash = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.dotn = -1;
	flag.mfw = 0;
	flag.bang = 0;
	flag.spce = 0;
	flag.plus = 0;
	flag.conv = 0;
	flag.lstr = 0;
	flag.str = NULL;
	flag.arg = 0;
	return (flag);
}

int	posnxtflag(char *str)
{
	int	i;

	i = 0;
	if (! str)
		return (0);
	while (str[i] && ! ft_isarg(str[i]))
		i++;
	return (i);
}

int isnamong(char *str, char c, int len)
{
	int	i;

	i = 0;
	if (! str || len <= 0)
		return (0);
	while (i < len && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	getflag1(t_flag *flag, char *s)
{
	int i;

	i = 0;
	if (! flag || ! s)
		return;
	while (i < posnxtflag(s) && s[i])
	{
		if (s[i] == '-')
			flag->dash = 1;
		if (s[i] == '0')
			flag->zero = 1;
		if (s[i] == '.')
		{
			flag->dot = 1;
			flag->dotn = 0;
		}
		if (s[i] == '#')
			flag->bang = 1;
		if (s[i] == ' ')
			flag->spce = 1;
		if (s[i] == '+')
			flag->plus = 1;
		i++;
	}
	flag->conv = s[i];
}

void	getflag2(t_flag *flag, char *s, va_list arg)
{
	int i;

	i = 0;
	if (! flag || ! s)
		return;
	while (i < posnxtflag(s) && s[i])
	{
		if (ft_isdigit(s[i]) && s[i] != '0' && flag->mfw == 0
				&& !isnamong(s, '.', i))
			flag->mfw = ft_atoi(s + i);
		if (s[i] == '.' && i + 1 < posnxtflag(s) && ft_isdigit(s[i + 1])
			&& s[i + 1]!= '0')
			flag->dotn = ft_atoi (s + i + 1);
		i++;
	}
	if(flag->conv != 's')
		flag->arg = va_arg(arg, long long);
	else
		flag->str = va_arg(arg, char *);
}

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
}

void	createstr(t_flag *flag)
{
}
//Attention gestion des - avant convertir base
