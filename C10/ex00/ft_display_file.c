/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:17:07 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/19 09:36:05 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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

int	file_name_missing(void)
{
	ft_putstr(2, "File name missing.\n");
	return (1);
}

int	too_many_arguments(void)
{
	ft_putstr(2, "Too many arguments.\n");
	return (1);
}

int	cannot_read_file(void)
{
	ft_putstr(2, "Cannot read file.\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int		index;
	char	buffer[1024];
	int		bytes_read;

	if (argc < 2)
		return (file_name_missing());
	else if (argc > 2)
		return (too_many_arguments());
	index = open(argv[1], O_RDONLY);
	if (index == -1)
		return (cannot_read_file());
	bytes_read = read(index, buffer, 10);
	while ((bytes_read > 0))
	{
		write(STDOUT_FILENO, buffer, bytes_read);
		bytes_read = read(index, buffer, 10);
	}
	if (bytes_read == -1)
		return (close(index), cannot_read_file());
	close(index);
	return (0);
}
