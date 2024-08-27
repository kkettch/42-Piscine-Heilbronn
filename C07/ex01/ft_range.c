/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:54:09 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 15:33:18 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*array;
	int		size;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = malloc(size * 4);
	if (array)
	{
		i = 0;
		while (i < (size))
		{
			array[i] = min;
			i++;
			min++;
		}
		return (array);
	}
	return (NULL);
}

int	main(void)
{
	int		i;
	int		min;
	int		max;
	int		*array;

	i = 0;
	min = -5;
	max = 6;
	array = ft_range(min, max);
	if (array)
	{
		while (i < (max - min))
		{
			printf("%d\n", array[i]);
			i++;
		}
	}
	else
		printf("%s\n", "NULL returned");
	return (0);
}