/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:33:18 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 12:41:11 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(int output, char *str);
void	print_error_message(char *name);
void	read_last_10_lines(int index, char *name);
int		print_last_n_chars(char *file_name, int n);
void	handle_flag(int argc, char **argv);
void	print_file_name(char *name);

void	handle_filename_output(int argc, int i, char *name)
{
	if (argc > 2)
	{
		if (i > 1)
			ft_putstr(1, "\n");
		print_file_name(name);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		index;

	if (argc == 1)
		return (read_last_10_lines(STDIN_FILENO, ""), 0);
	if (argv[1][0] == '-' && argv[1][1] == 'c')
		handle_flag(argc, argv);
	else
	{
		i = 1;
		while (argv[i])
		{
			index = open(argv[i], O_RDONLY);
			if (index == -1)
				print_error_message(argv[1]);
			else
			{
				handle_filename_output(argc, i, argv[i]);
				read_last_10_lines(index, argv[i]);
			}
			i++;
		}
	}
	return (0);
}
