/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:43:48 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/06 11:47:52 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	conv_u(t_flag *flag)
{
	flag->str = ft_uitoa(flag->arg);
	if (flag->dotn == 0 && flag->arg == 0)
	{
		free(flag->str);
		flag->str = ft_strdup("");
		if (!flag->str)
			return ;
	}
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
}

void	conv_percent(t_flag *flag)
{
	flag->str = ft_strdup("%");
	if (!flag->str)
		return ;
	if (!flag->zero)
		flag->str = mfwpad(flag, ' ', 0);
	if (flag->zero)
		flag->str = mfwpad(flag, '0', 0);
}

void	conv_zerochar(t_flag *flag)
{
	flag->str[0] = 42;
	flag->str = mfwpad(flag, ' ', 0);
}
