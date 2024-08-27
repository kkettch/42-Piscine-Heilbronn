/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:18:18 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/18 17:47:58 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*is_valid_input(int argc, char **argv);
void	dict_error(void);
void	output(char *file_name, char *number);
char	*get_file(int index);
char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	*file_name;
	char	*number;

	number = is_valid_input(argc, argv);
	if (number == NULL)
		return (0);
	if (argc == 3)
		file_name = argv[1];
	else
		file_name = "numbers.dict";
	output(file_name, number);
	return (0);
}
