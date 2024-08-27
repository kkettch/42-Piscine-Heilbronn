/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:42:35 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/11 16:42:57 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_zero(int **array, int *r, int *c);
int	is_row_unique(int i, int *r, int **array);
int	is_column_unique(int i, int *c, int **array);
int	check_row_if_finished(int *r, int *c, int **array);
int	check_column_if_finished(int *r, int *c, int **array);

int	is_valid(int i, int **array, int *r, int *c)
{
	if (!is_row_unique(i, r, array) || !is_column_unique(i, c, array))
		return (0);
	array[*r][*c] = i;
	if (check_row_if_finished(r, c, array) == 0)
		return (0);
	if (check_column_if_finished(r, c, array) == 0)
		return (0);
	array[*r][*c] = 0;
	return (1);
}

int	backtracking(int **array)
{
	int	r;
	int	c;
	int	i;

	if (is_zero(array, &r, &c) == 0)
		return (1);
	i = 1;
	while (i <= 4)
	{
		if (is_valid(i, array, &r, &c) == 1)
		{
			array[r][c] = i;
			if (backtracking(array) == 1)
				return (1);
			array[r][c] = 0;
		}
		i++;
	}
	return (0);
}
