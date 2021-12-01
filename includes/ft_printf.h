/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:43:46 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 18:07:44 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

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
	int			minus;
}			t_flag;

int			ft_printf(const char *s, ...);
int			ft_isarg(char c);
t_flag		initflag(void);
int			posnxtflag(char *str);
int			isnamong(char *str, char c, int len);
void		getflag1(t_flag *flag, char *s);
void		getflag2(t_flag *flag, char *s, va_list arg);
void		printflag(t_flag *flag);
void		cleanflag(t_flag *flag);
void		createstr(t_flag *flag);
char		*ft_catchzero(void);
char		*dotpad(t_flag *flag);
char		*ft_itohex(unsigned long long n, const char *base);
char		*ft_ptohex(void *p, const char *base);
char		*mfwpad(t_flag *flag, char padchar, int r);
long long	valabs(long long nb);
char		*addsign(t_flag *flag);
void		conv_di(t_flag *flag);
void		conv_xX(t_flag *flag);
char		*addprefix(t_flag *flag);
void		conv_bang(t_flag *flag);
char		*conv_percent(t_flag *flag);
void		conv_pt(t_flag *flag);
void		conv_str(t_flag *flag);
char		*chartostr(char c);

#endif
