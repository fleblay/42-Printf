/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:32:58 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/06 11:47:52 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	conv_di(t_flag *flag)
{
	flag->str = ft_ltoa(valabs(flag->arg));
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

static void	conv_bang(t_flag *flag)
{
	if (flag->conv == 'x')
		flag->str = ft_itohex(flag->arg, "0123456789abcdef");
	if (flag->conv == 'X')
		flag->str = ft_itohex(flag->arg, "0123456789ABCDEF");
	if (flag->dotn == 0 && flag->arg == 0)
	{
		free(flag->str);
		flag->str = ft_strdup("");
		if (!flag->str)
			return ;
	}
	if (flag->zero && flag->bang && flag->arg != 0)
		flag->str = mfwpad(flag, '0', 2);
	flag->str = dotpad(flag);
	if (flag->bang)
		flag->str = addprefix(flag);
	if (flag->dot && flag->dotn != 0)
		flag->str = mfwpad(flag, ' ', 0);
	if (!flag->zero && (flag->dotn == 0 || !flag->dot))
		flag->str = mfwpad(flag, ' ', 0);
	if (flag->zero && !flag->bang)
		flag->str = mfwpad(flag, '0', 0);
}

static void	conv_pt(t_flag *flag)
{
	flag->str = ft_ptohex((void *)flag->arg, "0123456789abcdef");
	flag->str = dotpad(flag);
	if (flag->dot && flag->dotn != 0)
		flag->str = mfwpad(flag, ' ', 0);
	flag->str = addprefix(flag);
	if (flag->dotn == 0 || !flag->dot)
		flag->str = mfwpad(flag, ' ', 0);
}

static void	conv_str(t_flag *flag)
{
	char	*tmp;

	tmp = NULL;
	if (flag->dot)
	{
		tmp = flag->str;
		flag->str = ft_substr(flag->str, 0, flag->dotn);
		if (! flag->str)
		{
			free (tmp);
			return ;
		}
		free (tmp);
	}
	flag->str = mfwpad(flag, ' ', 0);
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
		conv_percent(flag);
	if (flag->conv == 'p')
		conv_pt(flag);
	if (flag->conv == 'c')
		flag->str = chartostr(flag->arg);
	if (flag->conv == 'c' && flag->arg == 0)
		conv_zerochar(flag);
	if (flag->conv == 's' || flag->conv == 'c')
		conv_str(flag);
	if (flag->str)
		flag->lstr = ft_strlen(flag->str);
}
