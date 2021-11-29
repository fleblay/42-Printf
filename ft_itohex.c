/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:35:51 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/29 19:20:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_lennbhex(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	if (i > 8)
		i = 8;
	return (i);
}

static char	*ft_createtab(unsigned long long nbr)
{
	char	*tab;
	int		len;

	len = 0;
	tab = NULL;
	len = ft_lennbhex(nbr);
	tab = (char *)malloc((len + 3) * sizeof(char));
	if (! tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = 'x';
	tab[len + 2] = '\0';
	return (tab);
}

static char	*ft_catchzero(void)
{
	char	*tab;

	tab = NULL;
	tab = (char *)malloc(2 * sizeof(char));
	if (! tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itohex(unsigned long long n, const char *base)
{
	char				*tab;
	unsigned long long	nbr;
	int					i;

	tab = NULL;
	nbr = n;
	i = 0;
	if (nbr == 0)
		return (ft_catchzero());
	tab = ft_createtab(nbr);
	if (! tab)
		return (NULL);
	while (nbr > 0 && i < 8)
	{
		tab[ft_lennbhex(n) + 2 - 1 - i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	return (tab);
}

static int	ft_lenptrhex(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	if (i > 16)
		i = 16;
	return (i);
}

static char	*ft_createtabptr(unsigned long long nbr)
{
	char	*tab;
	int		len;

	len = 0;
	tab = NULL;
	len = ft_lenptrhex(nbr);
	tab = (char *)malloc((len + 3) * sizeof(char));
	if (! tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = 'x';
	tab[len + 2] = '\0';
	return (tab);
}

char	*ft_ptohex(void *p, const char *base)
{
	char				*tab;
	unsigned long long	nbr;
	int					i;

	tab = NULL;
	nbr = (unsigned long long) p;
	i = 0;
	if (nbr == 0)
		return (ft_catchzero());
	tab = ft_createtabptr(nbr);
	if (! tab)
		return (NULL);
	while (nbr > 0 && i < 16)
	{
		tab[ft_lenptrhex((unsigned long long)p) + 2 - 1 - i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	return (tab);
}

/*int main()
{
	char *fred = "abcdef";
	printf("%s\n", ft_itohex(256987, "0123456789abcdef"));
	printf("real : %#x\n", 256987);
	printf("%s\n", ft_itohex(-256987, "0123456789abcdef"));
	printf("real : %#x\n", -256987);
	printf("%s\n", ft_itohex(0, "0123456789abcdef"));
	printf("real : %#x\n", 0);
	printf("%s\n", ft_itohex(-25, "0123456789abcdef"));
	printf("real : %#x\n", -25);
	printf("%s\n", ft_itohex(-2147483647, "0123456789abcdef"));
	printf("real : %#x\n", -2147483647);
	printf("%s\n", ft_ptohex(fred, "0123456789abcdef"));
	printf("real : %p\n",  fred);
	printf("sizeof ptr : %lu\n", sizeof(void *));
	printf("sizeof int : %lu\n", sizeof(int));

	return (0);
}*/

// Tofix : utilisation de la base pour les 2 premiers bytes !
