/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:40:14 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/18 14:34:29 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_file(int index);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	dict_error(void);
void	input_error(void);
void	split_and_call(int size, char *number, char *file_name);
int		print_tens(int k, int size, char *number, char *file_name);
void	print_hundreds(int k, int size, char *number, char *file_name);
void	fill_temp(int size, char *temp);
int		print_thousands(int k, int size, char *number, char *file_name);
void	print_number(int k, char *number, char *file_name);

int	is_from_base(int size, char *number)
{
	int	i;

	i = 1;
	if (size == 2 && number[1] != '0')
		return (0);
	else if (size > 2 && number[0] == '1' && size % 3 == 1)
	{
		while (i < size)
		{
			if (number[i] != '0')
				return (0);
			i++;
		}
	}
	else if (size > 2 && size % 3 != 1)
		return (0);
	else if (size > 2 && size % 3 == 1 && number[0] != '1')
		return (0);
	return (1);
}

void	display_one_string(char **one_line_splitted)
{
	int	k;

	k = 1;
	while (one_line_splitted[k + 1])
	{
		ft_putstr(one_line_splitted[k++]);
		write(1, " ", 1);
	}
	ft_putstr(one_line_splitted[k]);
	return ;
}

int	output_one_digit(char *file_name, char *number)
{
	int		index;
	char	**lines;
	int		i;
	char	**one_line_splitted;

	i = 0;
	index = open(file_name, O_RDONLY);
	lines = ft_split(get_file(index), "\n");
	if (!lines)
		return (dict_error(), 0);
	while (lines[i])
	{
		one_line_splitted = ft_split(lines[i], " :");
		if (!one_line_splitted)
			return (dict_error(), 0);
		if (ft_strcmp(one_line_splitted[0], number) == 0)
		{
			display_one_string(one_line_splitted);
			break ;
		}
		i++;
		free(one_line_splitted);
	}
	free(lines);
	return (1);
}

void	split_and_call(int size, char *number, char *file_name)
{
	int		k;
	int		flag;

	k = 0;
	flag = 0;
	while (size > 0)
	{
		if (size % 3 == 2 && number[k] != '0')
			flag = print_tens(k, size, number, file_name);
		else if (size % 3 == 0 && number[k] != '0')
			print_hundreds(k, size, number, file_name);
		else if (size % 3 == 1 && size != 1)
			flag = print_thousands(k, size, number, file_name);
		if (size == 1 && number[k] != '0' && flag == 0)
			print_number(k, number, file_name);
		k++;
		size--;
	}
}

void	output(char *file_name, char *number)
{
	int	size;

	size = 0;
	while (number[size])
		size++;
	if (!is_from_base(size, number))
	{
		split_and_call(size, number, file_name);
		write(1, "\n", 1);
	}
	else
	{
		if (size > 2 && number[0] == '1')
		{
			output_one_digit(file_name, "1");
			write(1, " ", 1);
		}
		if (output_one_digit(file_name, number) == 1)
			write(1, "\n", 1);
	}
}
