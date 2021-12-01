/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:36:30 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/01 19:32:09 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	//printf("result %d\n", ft_printf("%c %c %c\n", '0', 90, 0));
	//printf("result %d\n", printf("%c %c %c\n", '0', 90, 0));
	//printf("result %d\n", ft_printf("'%c'\n", 0));
	//printf("%c", 0);
	ft_printf("%c", 0);
	//printf("result %d\n", ft_printf("%c\n", 'a'));
	//printf("result %d\n", printf("%c\n", 'a'));

	return (0);
}
