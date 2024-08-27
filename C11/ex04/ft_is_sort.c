/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:33:35 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/16 09:15:10 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	sorting_thing(int a, int b)
// {
// 	if (a < b)
// 		return (-5);
// 	else if (a == b)
// 		return (0);
// 	return (5);
// }

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sign;
	int	s;

	if (length <= 2)
		return (1);
	i = 0;
	sign = 0;
	while (sign == 0 && i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) != 0)
			sign = f(tab[i], tab[i + 1]);
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		s = f(tab[i], tab[i + 1]);
		if ((s < 0 && sign > 0) || (s > 0 && sign < 0))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int size = 5;
// 	int array[] = {1, 1, 1, 1, 1};
// 	printf("%d\n", ft_is_sort(array, size, &sorting_thing));
// 	return (0);
// }
