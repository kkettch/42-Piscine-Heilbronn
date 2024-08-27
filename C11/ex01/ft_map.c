/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:12:54 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:19 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// #include <stdio.h>

// int	ft_putnbr(int nb)
// {
// 	return (nb);
// }

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(length * sizeof(int));
	if (!result)
		return (NULL);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

// int main(void)
// {
// 	int size = 5;
// 	int *result;
// 	int array[] = {1, 2, 543, -4, -10000};
// 	result = ft_map(array, size, &ft_putnbr);
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d\n", result[i]);
// 	}
// 	return (0);
// }
