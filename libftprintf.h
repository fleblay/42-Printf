/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:09:57 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/26 19:42:27 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

typedef struct s_arg
{
	int		dash;
	int		zero;
	int		dot;
	int		dotn;
	int		mfw;
	int		bang;
	int		spce;
	int		plus;
	char	arg;
	int		len;
}			t_arg;

int	ft_printf(const char *s, ...);
int	ft_isarg(char c);

#endif
