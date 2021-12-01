/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:32:58 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 11:12:05 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

long long	valabs(long long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	createstr(t_flag *flag)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		conv_di(flag);
	if (flag->bang && (flag->conv == 'x' || flag->conv == 'X'))
		conv_bang(flag);
	if (!flag->bang && (flag->conv == 'x' || flag->conv == 'X'))
		conv_bang(flag);
	flag->lstr = ft_strlen(flag->str);
}

void	conv_di(t_flag *flag)
{
	flag->str = ft_itoa(valabs(flag->arg));
	flag->str = dotpad(flag);
	if (!flag->zero)
	{
		flag->str = addsign(flag);
		flag->str = mfwpad(flag, ' ', 0);
	}
	if (flag->zero)
	{
		flag->str = mfwpad(flag, '0', flag->minus | flag->plus | flag->spce);
		flag->str = addsign(flag);
	}
	flag->lstr = ft_strlen(flag->str);
}

/*
void	conv_xX(t_flag *flag)
{
	if (flag->conv == 'x')
		flag->str = ft_itohex(flag->arg, "0123456789abcdef");
	if (flag->conv == 'X')
		flag->str = ft_itohex(flag->arg, "0123456789ABCDEF");
	flag->str = dotpad(flag);
	if (!flag->zero)
		flag->str = mfwpad(flag, ' ', 0);
	else if (flag->zero)
		flag->str = addsign(flag);
	if (flag->bang)
		flag->str = addprefix(flag);
	flag->lstr = ft_strlen(flag->str);
}
*/
/*
void	conv_bang(t_flag *flag)
{
	if (flag->conv == 'x')
		flag->str = ft_itohex(flag->arg, "0123456789abcdef");
	if (flag->conv == 'X')
		flag->str = ft_itohex(flag->arg, "0123456789ABCDEF");
	flag->str = dotpad(flag);
	if (!flag->zero && flag->dot && flag->dotn != 0)
		flag->str = mfwpad(flag, ' ', 0);
	else if (flag->zero)
		flag->str = addsign(flag);
	if (flag->bang)
		flag->str = addprefix(flag);
	if (!flag->zero && (flag->dotn == 0 || !flag->dot))
		flag->str = mfwpad(flag, ' ', 0);
	flag->lstr = ft_strlen(flag->str);
}
*/

void	conv_bang(t_flag *flag)
{
	if (flag->conv == 'x')
		flag->str = ft_itohex(flag->arg, "0123456789abcdef");
	if (flag->conv == 'X')
		flag->str = ft_itohex(flag->arg, "0123456789ABCDEF");
	flag->str = dotpad(flag);
	if (flag->dot && flag->dotn != 0)
		flag->str = mfwpad(flag, ' ', 0);
	if (flag->bang)
		flag->str = addprefix(flag);
	if (flag->dotn == 0 || !flag->dot)
		flag->str = mfwpad(flag, ' ', 0);
	flag->lstr = ft_strlen(flag->str);
}
char	*addprefix(t_flag *flag)
{
	char	*tmp;

	tmp = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->conv == 'x' && flag->arg != 0)
	{
		tmp = ft_strjoin("0x", flag->str);
		if (!tmp)
			return (NULL);
		free(flag->str);
		flag->str = tmp;
	}
	if (flag->conv == 'X' && flag->arg != 0)
	{
		tmp = ft_strjoin("0X", flag->str);
		if (!tmp)
			return (NULL);
		free(flag->str);
		flag->str = tmp;
	}
	return (flag->str);
}


char	*dotpad(t_flag *flag)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	ret = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->lstr < flag->dotn)
	{
		tmp = ft_calloc(flag->dotn - flag->lstr + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		ft_memset(tmp, '0', flag->dotn - flag->lstr);
		ret = ft_strjoin(tmp, flag->str);
		if (!ret)
		{
			free(tmp);
			return (NULL);
		}
		free(flag->str);
		flag->str = ret;
	}
	return (flag->str);
}

char	*addsign(t_flag *flag)
{
	char	*tmp;

	tmp = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->minus)
	{
		tmp = ft_strjoin("-", flag->str);
		if (!tmp)
			return (NULL);
		free(flag->str);
		flag->str = tmp;
	}
	else if (flag->spce || flag->plus)
	{
		if (flag->spce)
			tmp = ft_strjoin(" ", flag->str);
		else if (flag->plus)
			tmp = ft_strjoin("+", flag->str);
		if (!tmp)
			return (NULL);
		free(flag->str);
		flag->str = tmp;
	}
	return (flag->str);
}

char	*mfwpad(t_flag *flag, char padchar, int r)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	ret = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->lstr + r < flag->mfw)
	{
		tmp = ft_calloc(flag->mfw - flag->lstr -r + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		ft_memset(tmp, padchar, flag->mfw - flag->lstr -r);
		if (flag->dash)
			ret = ft_strjoin(flag->str, tmp);
		else
			ret = ft_strjoin(tmp, flag->str);
		if (!ret)
		{
			free(tmp);
			return (NULL);
		}
		free(flag->str);
		flag->str = ret;
	}
	return (flag->str);
}
