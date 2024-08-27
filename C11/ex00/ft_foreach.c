/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:07:30 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:20 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

// void	ft_putnbr(int nb)
// {
// 	if (nb < 0)
// 	{
// 		if (nb == -2147483648)
// 		{
// 			write(1, "-2147483648", 11);
// 			return ;
// 		}
// 		write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb > 9)
// 		ft_putnbr(nb / 10);
// 	write(1, &((char){'0' + nb % 10}), 1);
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
	return ;
}

// int main(void)
// {
// 	int size = 5;
// 	int array[] = {1, 2, 543, -4, -10000};
// 	ft_foreach(array, size, &ft_putnbr);
// 	return (0);
// }
