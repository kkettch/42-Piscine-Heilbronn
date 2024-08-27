/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_10_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:32:44 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 10:43:56 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 10
#define BUFFER_SIZE 1024

void	print_error_message(char *name);
void	ft_putstr(int output, char *str);
void	manual_copy(char *dest, char *src, int size);
void	manual_shift_left(char *lines[], int line_lengths[], int max_lines);
void	print_lines(char *lines[], int line_lengths[], int line_count);

#define MAX_LINES 10
#define BUFFER_SIZE 1024

typedef struct name_line {
	char	*lines[MAX_LINES];
	int		line_lengths[MAX_LINES];
	int		line_count;
}	t_line;

typedef struct name_buffer {
	char	*buffer;
	int		offset;
}	t_buffer;

typedef struct name_params {
	t_buffer	*buffer;
	t_line		*storage;
	char		*name;
	int			index;
}	t_process_params;

void	handle_line(t_line *storage, char *line, int line_length)
{
	if (storage->line_count < MAX_LINES)
	{
		storage->lines[storage->line_count] = line;
		storage->line_lengths[storage->line_count] = line_length;
		(storage->line_count)++;
	}
	else
	{
		manual_shift_left(storage->lines, storage->line_lengths, MAX_LINES);
		storage->lines[MAX_LINES - 1] = line;
		storage->line_lengths[MAX_LINES - 1] = line_length;
	}
}

void	process_line(t_process_params *params, int start, int end)
{
	int		line_length;
	char	*line;

	line_length = end - start + 1;
	line = (char *)malloc(line_length + 1);
	if (!line)
	{
		print_error_message(params->name);
		close(params->index);
		return ;
	}
	manual_copy(line, params->buffer->buffer + start, line_length);
	line[line_length] = '\0';
	handle_line(params->storage, line, line_length);
}

void	update_buffer(t_buffer *buffer_data, int start)
{
	int	j;

	j = 0;
	if (start < buffer_data->offset)
	{
		while (j < buffer_data->offset - start)
		{
			buffer_data->buffer[j] = buffer_data->buffer[start + j];
			j++;
		}
		buffer_data->offset -= start;
	}
	else
	{
		buffer_data->offset = 0;
	}
}

void	process_buffer(t_buffer *b, t_line *storage, char *name, int index)
{
	int					i;
	int					start;
	t_process_params	params;

	params.buffer = b;
	params.storage = storage;
	params.name = name;
	params.index = index;
	i = 0;
	start = 0;
	while (i < b->offset)
	{
		if (b->buffer[i] == '\n' || i == b->offset - 1)
		{
			process_line(&params, start, i);
			start = i + 1;
		}
		i++;
	}
	update_buffer(b, start);
}

void	read_last_10_lines(int index, char *name)
{
	t_line		storage;
	t_buffer	b;
	int			bytes_read;

	storage.line_count = 0;
	b.buffer = malloc(BUFFER_SIZE);
	b.offset = 0;
	if (!b.buffer)
		return (print_error_message(name));
	bytes_read = read(index, b.buffer + b.offset, BUFFER_SIZE - b.offset);
	b.offset += bytes_read;
	while (bytes_read > 0)
	{
		process_buffer(&b, &storage, name, index);
		bytes_read = read(index, b.buffer + b.offset, BUFFER_SIZE - b.offset);
		b.offset += bytes_read;
	}
	if (bytes_read == -1)
		print_error_message(name);
	else
		print_lines(storage.lines, storage.line_lengths, storage.line_count);
	free(b.buffer);
}
