/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:57:35 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/11 16:42:55 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_zero(int **array, int *r, int *c)
{
	*r = 0;
	while (*r != 4)
	{
		*c = 0;
		while (*c != 4)
		{
			if (array[*r][*c] == 0)
				return (1);
			*c = *c + 1;
		}
		*r = *r + 1;
	}
	return (0);
}

int	is_left(int a, int *array)
{
	int	i;
	int	counter;
	int	start_point;

	i = 1;
	counter = 1;
	start_point = array[0];
	while (i < 4)
	{
		if (start_point < array[i])
		{
			start_point = array[i];
			counter++;
		}
		i++;
	}
	if (counter != a)
		return (0);
	return (1);
}

int	is_right(int b, int *array)
{
	int	i;
	int	counter;
	int	start_point;

	i = 3;
	counter = 1;
	start_point = array[3];
	while (i >= 0)
	{
		if (start_point < array[i])
		{
			start_point = array[i];
			counter++;
		}
		i--;
	}
	if (counter != b)
		return (0);
	return (1);
}

int	is_line_valid(int a, int b, int *array)
{
	int	counter;

	counter = 1;
	if (!is_left(a, array) || !is_right(b, array))
		return (0);
	return (1);
}

int	is_line_filled(int *array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (array[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
