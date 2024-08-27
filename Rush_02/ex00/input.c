/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:04:41 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/18 17:38:46 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	input_error(void);
void	dict_error(void);
int		ft_strcmp(char *s1, char *s2);
int		check_dictionary(char *file);

int	is_file_exist(char **argv)
{
	int	index;

	index = open(argv[1], O_RDONLY);
	if (index == -1)
		return (0);
	return (close(index), 1);
}

char	*is_valid_input(int argc, char **argv)
{
	int		i;
	char	*number;

	if (argc != 2 && argc != 3)
		return (input_error(), NULL);
	i = 0;
	number = argv[argc - 1];
	while (number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
			return (input_error(), NULL);
		i++;
	}
	if (argc == 3)
	{
		if (!is_file_exist(argv) && !check_dictionary(argv[1]))
			return (dict_error(), NULL);
	}
	else
	{
		if (!check_dictionary("numbers.dict"))
			return (dict_error(), NULL);
	}
	return (number);
}
