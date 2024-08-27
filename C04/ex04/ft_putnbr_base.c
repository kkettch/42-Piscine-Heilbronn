/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:28:10 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/13 20:10:59 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_unique(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_recursive(int nbr, char *base, int base_size)
{
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_recursive((-1 * (nbr / base_size)), base, base_size);
		write(1, &base[2147483648 % base_size], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -1 * nbr;
	}
	if (nbr >= base_size)
		ft_recursive(nbr / base_size, base, base_size);
	write(1, &base[nbr % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		bs;

	bs = 0;
	while (base[bs] != '\0')
	{
		if (base[bs] == '+' || base[bs] == '-' || base[bs] == ' ')
			return ;
		bs++;
	}
	if (bs <= 1 || !is_unique(base))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_recursive(nbr, base, bs);
	return ;
}

#include<stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char str[] = "SalLUt, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}