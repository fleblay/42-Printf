/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:52:54 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/03 15:53:54 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

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
	flag.minus = 0;
	return (flag);
}

void	getflag1(t_flag *flag, char *s)
{
	int	i;

	i = 0;
	if (! flag || ! s)
		return ;
	while (i < posnxtflag(s) && s[i])
	{
		if (s[i] == '-')
			flag->dash = 1;
		if (s[i] == '0' && isnamong("%-0+ #", s[i - 1], 6))
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

void	getflag2(t_flag *flag, char *s)
{
	int	i;

	i = 0;
	if (! flag || ! s)
		return ;
	while (i < posnxtflag(s) && s[i])
	{
		if (ft_isdigit(s[i]) && s[i] != '0' && flag->mfw == 0
			&& !isnamong(s, '.', i))
			flag->mfw = ft_atoi(s + i);
		if (s[i] == '.' && i + 1 < posnxtflag(s) && ft_isdigit(s[i + 1])
			&& s[i + 1] != '0')
			flag->dotn = ft_atoi (s + i + 1);
		i++;
	}
}

void	getarg(t_flag *flag, va_list arg)
{
	char	*tmp;

	tmp = NULL;
	if (flag->conv == 'p')
		flag->arg = va_arg(arg, unsigned long long);
	else if (flag->conv == 'u')
		flag->arg = va_arg(arg, unsigned int);
	else if (flag->conv == 's')
	{
		tmp = va_arg(arg, char *);
		if (tmp)
			flag->str = ft_strdup(tmp);
		else
			flag->str = ft_strdup("(null)");
	}
	else if (flag->conv != '%')
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
	if (flag->bang == 1 && flag->zero == 1 && flag->dot)
		flag->zero = 0;
	if (flag->minus == 1 && flag->spce == 1)
		flag->spce = 0;
	if (flag->minus == 1 && flag->plus == 1)
		flag->plus = 0;
}
