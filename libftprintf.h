/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:09:57 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/29 15:59:24 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>

typedef struct s_flag
{
	int			dash;
	int			zero;
	int			dot;
	int			dotn;
	int			mfw;
	int			bang;
	int			spce;
	int			plus;
	char		conv;
	int			lstr;
	char		*str;
	long long	arg;
}			t_flag;

int	ft_printf(const char *s, ...);
int	ft_isarg(char c);
t_flag	initflag(void);
int	posnxtflag(char *str);
int isnamong(char *str, char c, int len);
void	getflag1(t_flag *flag, char *s);
void	getflag2(t_flag *flag, char *s, va_list arg);
void	printflag(t_flag *flag);

#endif
