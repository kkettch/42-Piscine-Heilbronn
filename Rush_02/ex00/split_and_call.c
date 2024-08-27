/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:17:33 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/18 14:26:36 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	output_one_digit(char *file_name, char *number);

int	print_tens(int k, int size, char *number, char *file_name)
{
	char	new[3];
	int		flag;

	flag = 0;
	if (number[k] == '1' || (number[k + 1] == '0' && number[k] != '0'))
	{
		flag = 1;
		new[0] = number[k];
		new[1] = number[k + 1];
		new[2] = '\0';
		output_one_digit(file_name, new);
	}
	else if (number[k] != '0' && number[k] != '1')
	{
		new[0] = number[k];
		new[1] = '0';
		new[2] = '\0';
		output_one_digit(file_name, new);
		write(1, " ", 1);
	}
	if (size > 2)
		write(1, " ", 1);
	return (flag);
}

void	print_hundreds(int k, int size, char *number, char *file_name)
{
	char	tmp_number[2];

	if (number[k] != '0')
	{
		tmp_number[0] = number[k];
		tmp_number[1] = '\0';
		output_one_digit(file_name, tmp_number);
		write(1, " ", 1);
	}
	if (number[k] != '0')
		output_one_digit(file_name, "100");
	if (size > 2)
		write(1, " ", 1);
	return ;
}

void	fill_temp(int size, char *temp)
{
	int	i;

	i = 1;
	temp[0] = '1';
	while (i < size)
	{
		temp[i] = '0';
		i++;
	}
	temp[i] = '\0';
}

int	is_zero(int k, char *number)
{
	int	i;

	i = k + 1;
	while (number[i] != '\0')
	{
		if (number[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	print_thousands(int k, int size, char *number, char *file_name)
{
	char	*temp;
	char	tmp_number[2];

	if ((k == 0) || (number[k] != '0'
			&& (number[k - 1] == '0' || number[k - 2] == '0')))
	{
		tmp_number[0] = number[k];
		tmp_number[1] = '\0';
		output_one_digit(file_name, tmp_number);
		write(1, " ", 1);
	}
	if (number[k] != '0' || (number[k - 1] != '0'
			|| number[k - 2] != '0'))
	{
		temp = (char *)malloc(size + 1);
		if (!temp)
			return (1);
		fill_temp(size, temp);
		output_one_digit(file_name, temp);
		free(temp);
	}
	if (is_zero(k, number) == 0)
		write(1, " ", 1);
	return (0);
}

void	print_number(int k, char *number, char *file_name)
{
	char	tmp_number[2];

	tmp_number[0] = number[k];
	tmp_number[1] = '\0';
	output_one_digit(file_name, tmp_number);
}
