/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:22:45 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 14:50:48 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int		count_minus_sign;
	int		result;

	count_minus_sign = 0;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count_minus_sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (count_minus_sign % 2 == 1)
		result = -1 * result;
	return (result);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (s1[i] - s2[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}
