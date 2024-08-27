/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:47:44 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/21 08:32:45 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void	fill_old_value(int total_size, char *buffer, char *new_buffer)
{
	int	i;

	i = 0;
	while (i < total_size)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
}

char	*fill_new_value(int total, int bytes_read, char *new_buffer, char *temp)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		new_buffer[total + i] = temp[i];
		i++;
	}
	return (new_buffer);
}

char	*get_file(int index)
{
	char	*buffer;
	char	temp[BUFFER_SIZE];
	int		total_size;
	int		bytes_read;
	char	*new_buffer;

	buffer = NULL;
	total_size = 0;
	bytes_read = read(index, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		new_buffer = (char *)malloc(total_size + bytes_read);
		if (!new_buffer)
			return (free(buffer), close(index), NULL);
		if (buffer)
			fill_old_value(total_size, buffer, new_buffer);
		buffer = fill_new_value(total_size, bytes_read, new_buffer, temp);
		total_size += bytes_read;
		bytes_read = read(index, temp, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buffer), close(index), NULL);
	return (buffer);
}
