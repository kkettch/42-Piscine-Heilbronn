/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:13:02 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/11 16:45:00 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_line_valid(int a, int b, int *array);
int	is_line_filled(int *array);

int	is_row_unique(int i, int *r, int **array)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (array[*r][k] == i)
			return (0);
		k++;
	}
	return (1);
}

int	is_column_unique(int i, int *c, int **array)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (array[k][*c] == i)
			return (0);
		k++;
	}
	return (1);
}

int	check_row_if_finished(int *r, int *c, int **array)
{
	int	counter;
	int	copy[4];

	counter = 0;
	while (counter < 4)
	{
		copy[counter] = array[*r][counter];
		counter++;
	}
	if (is_line_filled(copy))
	{
		if (is_line_valid(array[6][*r], array[7][*r], copy) == 0)
		{
			array[*r][*c] = 0;
			return (0);
		}
	}
	return (1);
}

int	check_column_if_finished(int *r, int *c, int **array)
{
	int	counter;
	int	copy[4];

	counter = 0;
	while (counter < 4)
	{
		copy[counter] = array[counter][*c];
		counter++;
	}
	if (is_line_filled(copy))
	{
		if (is_line_valid(array[4][*c], array[5][*c], copy) == 0)
		{
			array[*r][*c] = 0;
			return (0);
		}
	}
	return (1);
}
