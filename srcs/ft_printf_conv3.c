/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:13 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/02 18:03:43 by fle-blay         ###   ########.fr       */
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
void	conv_zerochar(t_flag *flag)
{
	flag->str[0] = 9;
	flag->str = mfwpad(flag, ' ', 0);
}

void	ft_putnstrzero_fd(char *s, int fd, int size)
{
	int	i;

	i = 0;
	if (! s)
		return ;
	while (i < size)
	{
		if (s[i] == 9)
			s[i] = 0;
		write(fd, s + i, 1);
		i++;
	}
}

void	conv_u(t_flag *flag)
{
	//printf("argb : %u\n", (unsigned int)flag->arg);
	//printf("argbis : %u\n", (unsigned int)(valabs(flag->arg)));
	flag->str = ft_uitoa(flag->arg);
	//flag->str = ft_itoa(valabs(flag->arg));
	//printf("argc : %s\n", flag->str);
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
