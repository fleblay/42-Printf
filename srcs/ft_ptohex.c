/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:50:14 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/03 11:18:26 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (! tab)
		return (NULL);
	tab[len] = '\0';
	return (tab);
}

static char	*ft_catchz(void)
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

char	*ft_ptohex(void *p, const char *base)
{
	char				*tab;
	unsigned long long	nbr;
	int					i;

	tab = NULL;
	nbr = (unsigned long long) p;
	i = 0;
	if (nbr == 0)
		return (ft_catchz());
	tab = ft_createtabptr(nbr);
	if (! tab)
		return (NULL);
	while (nbr > 0 && i < 16)
	{
		tab[ft_lenptrhex((unsigned long long)p) - 1 - i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	return (tab);
}
