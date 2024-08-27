/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:24:20 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 15:33:28 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*array;
	int		size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(size * 4);
	if (array)
	{
		i = 0;
		while (i < (size))
		{
			array[i] = min;
			i++;
			min++;
		}
		*range = array;
		return (size);
	}
	*range = NULL;
	return (-1);
}

int	main(void)
{
	int		i;
	int		min;
	int		max;
	int		size;
	int		*range;

	i = 0;
	min = 0;
	max = 7;
	size = ft_ultimate_range(&range, min, max);
	if (size == -1) 
	{
        printf("Error: Memory allocation failed\n");
    } else if (size == 0) 
	{
        printf("Range is NULL for min = %d and max = %d\n", min, max);
    } else 
	{
        printf("Range from %d to %d (size = %d):\n", min, max, size);
        for (i = 0; i < size; i++) 
		{
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);
    }
	return (0);
}