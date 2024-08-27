/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_last_n_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:55:39 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:22 by mchmurov         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (s1[i] - s2[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}

int	get_start(int n, int total_read)
{
	int	start;

	start = 0;
	if (total_read < n)
	{
		start = 0;
		n = total_read;
	}
	else
		start = total_read % n;
	return (start);
}

void	print_buffer(int start, int n, char *buffer)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(STDOUT_FILENO, &buffer[(start + i) % n], 1);
		i++;
	}
}

int	get_fd(char *file_name)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(file_name, "") == 0)
		fd = STDIN_FILENO;
	else
		fd = open(file_name, O_RDONLY);
	return (fd);
}

int	print_last_n_chars(char *file_name, int n)
{
	int		fd;
	char	*buffer;
	int		bytes_read;
	int		total_read;

	total_read = 0;
	fd = get_fd(file_name);
	if (fd == -1)
		return (print_error_message(file_name), 0);
	buffer = (char *)malloc(n);
	if (!buffer)
		return (close(fd), print_error_message(file_name), 0);
	bytes_read = read(fd, buffer + total_read % n, 1);
	while (bytes_read > 0)
	{
		total_read++;
		bytes_read = read(fd, buffer + total_read % n, 1);
	}
	if (bytes_read == -1)
		return (free(buffer), close(fd), print_error_message(file_name), 0);
	print_buffer(get_start(n, total_read), n, buffer);
	return (free(buffer), close(fd), 1);
}
