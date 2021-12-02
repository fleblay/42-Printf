/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:32:58 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/02 12:40:44 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
	if (flag->conv == 'u')
		conv_u(flag);
	if (flag->conv == 'x' || flag->conv == 'X')
		conv_bang(flag);
	if (flag->conv == '%')
		flag->str = conv_percent(flag);
	if (flag->conv == 'p')
		conv_pt(flag);
	if (flag->conv == 'c')
		flag->str = chartostr(flag->arg);
	if (flag->conv == 'c' && flag->arg == 0)
		conv_zerochar(flag);
	if (flag->conv == 's' || flag->conv == 'c')
		conv_str(flag);
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

void	conv_pt(t_flag *flag)
{
	flag->str = ft_ptohex((void *)flag->arg, "0123456789abcdef");
	flag->str = dotpad(flag);
	if (flag->dot && flag->dotn != 0)
		flag->str = mfwpad(flag, ' ', 0);
	flag->str = addprefix(flag);
	if (flag->dotn == 0 || !flag->dot)
		flag->str = mfwpad(flag, ' ', 0);
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
