/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:06:27 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/11 16:43:02 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	backtracking(int **array);
int	is_input_valid(char *char_input);
int	**fill_result(char *char_input);

void	write_error(void)
{
	write(1, "Error\n", 6);
	return ;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_board(int **board)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			ft_putchar(board[y][x] + '0');
			x++;
			if (i < 3)
			{
				ft_putchar(' ');
				i++;
			}
		}
		i = 0;
		x = 0;
		y++;
		write(1, "\n", 1);
	}
}

void	free_memory(int **array)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	main(int argc, char **argv)
{
	char	*char_input;
	int		**result;

	char_input = NULL;
	if (argc == 2)
		char_input = argv[1];
	else
	{
		write_error();
		return (0);
	}
	if (is_input_valid(char_input) == 0)
	{
		write_error();
		return (0);
	}
	result = fill_result(char_input);
	if (backtracking(result))
	{
		write_board(result);
	}
	else
		write_error();
	free_memory(result);
	return (0);
}
