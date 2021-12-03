/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:44:16 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/03 11:22:58 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*mfwpad(t_flag *flag, char padchar, int r)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	flag->lstr = ft_strlen(flag->str);
	if (flag->lstr + r < flag->mfw)
	{
		tmp = ft_calloc(flag->mfw - flag->lstr - r + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		ft_memset(tmp, padchar, flag->mfw - flag->lstr - r);
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
		free(tmp);
		flag->str = ret;
	}
	return (flag->str);
}

char	*addprefix(t_flag *flag)
{
	char	*tmp;

	tmp = NULL;
	flag->lstr = ft_strlen(flag->str);
	if ((flag->conv == 'x' && flag->arg != 0) || flag->conv == 'p')
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
		free(tmp);
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
