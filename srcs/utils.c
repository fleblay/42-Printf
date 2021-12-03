/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:52:36 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/03 11:32:58 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isarg(char c)
{
	int			i;
	static char	*arg = "cspdiuxX%";

	i = 0;
	while (i < 9)
	{
		if (c == arg[i])
			return (1);
		i++;
	}
	return (0);
}

int	posnxtflag(char *str)
{
	int	i;

	i = 0;
	if (! str)
		return (0);
	while (str[i] && ! ft_isarg(str[i]))
		i++;
	return (i);
}

int	isnamong(char *str, char c, int len)
{
	int	i;

	i = 0;
	if (! str || len <= 0)
		return (0);
	while (i < len && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long long	valabs(long long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_putnstrzero_fd(char *s, int fd, int size)
{
	int	i;

	i = 0;
	if (! s)
		return ;
	while (i < size)
	{
		if (s[i] == 42)
			s[i] = 0;
		write(fd, s + i, 1);
		i++;
	}
}
