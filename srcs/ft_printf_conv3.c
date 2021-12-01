/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:13 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 15:49:00 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

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
