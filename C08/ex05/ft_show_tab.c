/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:39:12 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/13 10:22:54 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &((char){'0' + nb % 10}), 1);
}

void	ft_putsrt(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (par[i].str)
	{
		ft_putsrt(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		string = par[i].copy;
		while (string[j] != '\0')
		{
			write(1, &string[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}
