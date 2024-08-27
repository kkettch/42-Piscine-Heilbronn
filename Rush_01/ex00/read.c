/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:17:32 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/11 16:43:04 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_input_valid(char *char_input)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (char_input[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(char_input[i] >= '1' && char_input[i] <= '4'))
				return (0);
		}
		else
		{
			if (!(char_input[i] == ' '))
				return (0);
		}
		i++;
		size++;
	}
	if (size > 31)
		return (0);
	return (1);
}

int	**malloc_array(void)
{
	int	i;
	int	**result;

	i = 0;
	result = (int **)malloc(8 * 8);
	while (i < 8)
	{
		result[i] = (int *)malloc(4 * 4);
		i++;
	}
	return (result);
}

void	fill_zeros(int **result)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			result[i][j] = 0;
			j++;
		}
		i++;
	}
	return ;
}

int	**fill_result(char *char_input)
{
	int	i;
	int	j;
	int	**result;
	int	value;

	result = malloc_array();
	fill_zeros(result);
	i = 4;
	value = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			result[i][j] = char_input[value] - '0';
			j++;
			value = value + 2;
		}
		i++;
	}
	return (result);
}
