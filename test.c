/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:36:30 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/10 15:21:23 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	//printf("result %d\n", ft_printf("%c %c %c\n", '0', 90, 0));
	//printf("result %d\n", printf("%c %c %c\n", '0', 90, 0));
	//printf("result %d\n", ft_printf("'%c'\n", 0));
	//printf("%10c", 0);
	//printf("%10c", 0);
	//printf("%10.c", 0);
	//printf("%10.c", 0);
	//printf("%10c", 0);
	//printf("result %d\n", ft_printf("%c\n", 'a'));
	//printf("result %d\n", printf("%c\n", 'a'));
	//printf("a%sa", NULL);
	//ft_printf("%d\n", -2147483648);	
	//ft_printf("%d\n", -2147483647);	
	//ft_printf("%u\n", -1);	
	//ft_printf("%u\n", -2);	
	//ft_printf("%u\n", -3);	
	//printf("%u\n", -1);	
	//ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	//ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42);
	//ft_printf("%c\n", 'A');
	//ft_printf("%c\n", 'B');
	//ft_printf("%%%c", 'A');
	//printf("%d\n", ft_printf("%u\n", -1));	
	//printf("%d\n", (int)-2147483648);	
	//ft_printf("%04x", 9);
	//printf("\n");
	//printf("%04x", 9);
	//ft_printf("%10d\n", 42);
	//printf("%10d\n", 42);
	//
	//ft_printf("%.13d\n", -2147);
	//printf("%.13d\n", -2147);
	//ft_printf("%.13d\n", (int)-2147483647);
	//printf("%.13d\n", (int)-2147483647);
	//ft_printf("%.13d\n", (int)-2147483648);
	//printf("%.13d\n", (int)-2147483648);
	//printf("%014d\n", (int)-2147483647);
	//ft_printf("%014d\n", (int)-2147483647);
	//printf("%014d\n", (int)-2147483648);
	//ft_printf("%014d\n", (int)-2147483648);
	//ft_printf("%d\n", 0);
	//printf("%d\n", 0);
	//ft_printf("%.1d\n", 0);
	//printf("%.1d\n", 0);
	//ft_printf("%d\n", 0);
	//printf("%d\n", 0);
	//ft_printf("%.0d\n", 0);
	//printf("%.0d\n", 0);
	//ft_printf("%8.0d\n", 0);
	//printf("%8.0d\n", 0);
	//ft_printf("%.0d\n", 9);
	//printf("%.0d\n", 9);
	//printf("%#015x\n", 42);
	//ft_printf("%#015x\n", 42);
	//printf("%#015.10x\n", 42);
	//ft_printf("%#015.10x\n", 42);
	//printf("%015.10x\n", 42);
	//ft_printf("%015.10x\n", 42);
	//printf("%4d\n", -12);
	//ft_printf("%4d\n", -12);
	//printf("%04.4d\n", -12);
	//printf("%04.4d\n", -12);
	//
	ft_printf("'%5%'\n");
	printf("'%5%'\n");
	//ft_printf("'%012.5%'\n");
	//printf("'%012.5%'\n");
	//ft_printf("'%012.%'\n");
	//printf("'%012.%'\n");
	//ft_printf("'%-12.5%'\n");
	//printf("'%-12.5%'\n");
	//ft_printf("'%0.5%'\n");
	//printf("'%0.5%'\n");
	//ft_printf("'%-8.5%'\n");
	//printf("'%-8.5%'\n");
	//ft_printf("'%8.5s'\n", "abcdefghi");
	//printf("'%8.5s'\n", "abcdefghi");
	//ft_printf("'%-8.5s'\n", "abcdefghi");
	//printf("'%-8.5s'\n", "abcdefghi");
	//ft_printf("'%.05s'\n", "abcdefghi");
	//printf("'%.05s'\n", "abcdefghi");
	//ft_printf("'%.5s'\n", "abcdefghi");
	//printf("'%.5s'\n", "abcdefghi");
	printf("%.10%\n");
	ft_printf("%.10%\n");

	//while (1);

	return (0);
}
