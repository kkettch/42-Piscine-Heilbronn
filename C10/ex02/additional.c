/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:57 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 12:40:26 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 10
#define BUFFER_SIZE 1024

void	ft_putstr(int output, char *str);

void	print_file_name(char *name)
{
	ft_putstr(1, "==> ");
	ft_putstr(1, name);
	ft_putstr(1, " <==");
	ft_putstr(1, "\n");
}

void	manual_copy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	manual_shift_left(char *lines[], int line_lengths[], int max_lines)
{
	int	i;

	free(lines[0]);
	i = 1;
	while (i < max_lines)
	{
		lines[i - 1] = lines[i];
		line_lengths[i - 1] = line_lengths[i];
		i++;
	}
}

void	print_lines(char *lines[], int line_lengths[], int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		write(1, lines[i], line_lengths[i]);
		free(lines[i]);
		i++;
	}
}
