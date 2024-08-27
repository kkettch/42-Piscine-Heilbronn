/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:22:29 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/19 14:52:57 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_all_queens(int *row, int *result)
{
	*row = 0;
	while (*row < 10)
	{
		if (result[*row] == -1)
			return (0);
		*row = *row + 1;
	}
	return (1);
}

int	is_valid(int p, int *result, int row)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (result[i] == p)
			return (0);
		else if (i < row)
		{
			if (result[i] == p - (row - i) && (p - (row - i)) >= 0)
				return (0);
			if (result[i] == p + (row - i) && (p + (row - i)) <= 9)
				return (0);
		}
		else if (i > row)
		{
			if (result[i] == p - (i - row) && (p - (i - row)) >= 0)
				return (0);
			if (result[i] == p + (i - row) && (p + (i - row)) <= 9)
				return (0);
		}
		i++;
	}
	return (1);
}

void	print_result(int *result)
{
	int		i;
	char	number;

	i = 0;
	while (i < 10)
	{
		number = result[i] + '0';
		write(1, &number, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	backtracking(int *result)
{
	int	row;
	int	solutions;
	int	i;

	solutions = 0;
	if (is_all_queens(&row, result))
	{
		print_result(result);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (is_valid(i, result, row))
		{
			result[row] = i;
			solutions += backtracking(result);
			result[row] = -1;
		}
		i++;
	}
	return (solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	result[10];

	i = 0;
	while (i < 10)
	{
		result[i] = -1;
		i++;
	}
	return (backtracking(result));
}

// int	main(void)
// {
// 	printf("%d\n", ft_ten_queens_puzzle());
// 	return (0);
// }
