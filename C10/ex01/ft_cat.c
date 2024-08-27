/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:07:53 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/19 11:24:44 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 29696

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

void	ft_putstr(int output, char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(output, (str + i), 1);
		i++;
	}
}

void	print_error_message(char *name)
{
	ft_putstr(STDERR_FILENO, "ft_cat: ");
	ft_putstr(STDERR_FILENO, name);
	ft_putstr(STDERR_FILENO, ": ");
	ft_putstr(STDERR_FILENO, strerror(errno));
	ft_putstr(STDERR_FILENO, "\n");
}

void	print_file(char *name)
{
	int		index;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	index = open(name, O_RDONLY);
	if (index == -1)
		return (print_error_message(name));
	bytes_read = read(index, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) == -1)
			return (print_error_message(name));
		bytes_read = read(index, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (close(index), print_error_message(name));
	close(index);
	return ;
}

void	read_terminal(void)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) == -1)
			return (print_error_message("-"));
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (print_error_message("-"));
	return ;
}
