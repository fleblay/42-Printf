/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:32:58 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/30 18:03:37 by fle-blay         ###   ########.fr       */
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
		flag->str = ft_itoa(valabs(flag->arg));
//	printf("val %lld\n", flag->arg);
//	printf("valabs %lld\n", valabs(flag->arg));
	//Mettres toutes les conv de base au dessus
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

char	*dotpad(t_flag *flag)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	ret = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->conv != 's' && flag->lstr < flag->dotn)
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
	if (flag->conv != 's' && flag->minus)
	{
		tmp = ft_strjoin("-", flag->str);
		if (!tmp)
			return (NULL);
		free(flag->str);
		flag->str = tmp;
	}
	else if (flag->conv != 's' && (flag->spce || flag->plus))
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
	if (flag->conv != 's' && flag->lstr + r < flag->mfw)
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
