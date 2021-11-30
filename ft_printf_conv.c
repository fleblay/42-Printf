/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:32:58 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/30 12:21:01 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	createstr(t_flag *flag)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_itoa(flag->arg);
	//Mettres toutes les conv de base au dessus
	flag->str = dotpad(flag);
	//faire mfw
	//faire +
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
