/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:32:22 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:48 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(int output, char *str);
void	error_illegal_offset(char *number);
int		print_last_n_chars(char *file_name, int n);
void	print_file_name(char *name);

void	handle_filename_output_with_flag(int argc, int i, char *name)
{
	if (argc > 3)
	{
		if (i > 2)
			ft_putstr(1, "\n");
		print_file_name(name);
	}
}

int	ft_atoi(char *str)
{
	int		count_minus_sign;
	int		result;

	count_minus_sign = 0;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count_minus_sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (count_minus_sign % 2 == 1)
		result = -1 * result;
	return (result);
}

int	is_valid_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '\0')
		return (0);
	while (number[i] == ' ')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
		i++;
	if (number[i] != '\0')
		return (0);
	return (1);
}

void	handle_flag(int argc, char **argv)
{
	int		i;
	char	*number_position;

	argv[1] += 2;
	if (argv[1][0] == '\0')
		number_position = argv[2];
	else
		number_position = argv[1];
	if (!is_valid_number(number_position))
		return (error_illegal_offset(number_position));
	if ((argv[1][0] == '\0' && argc == 3)
			|| (argv[1][0] != '\0' && argc == 2))
		print_last_n_chars("", ft_atoi(number_position));
	else
	{
		i = 2;
		if (argv[1][0] == '\0' && argc > 3)
			i = 3;
		while (argv[i])
		{
			if (open(argv[i], O_RDONLY) != -1)
				handle_filename_output_with_flag(argc, i, argv[i]);
			print_last_n_chars(argv[i++], ft_atoi(number_position));
		}
	}
}
