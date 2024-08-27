/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:42:48 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/22 12:40:41 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(int output, char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(output, (str + i), 1);
		i++;
	}
}

void	error_illegal_offset(char *number)
{
	ft_putstr(STDERR_FILENO, "ft_tail: ");
	ft_putstr(STDERR_FILENO, "illegal offset -- ");
	ft_putstr(STDERR_FILENO, number);
	ft_putstr(STDERR_FILENO, "\n");
}

void	print_error_message(char *name)
{
	ft_putstr(STDERR_FILENO, "ft_tail: ");
	ft_putstr(STDERR_FILENO, name);
	ft_putstr(STDERR_FILENO, ": ");
	ft_putstr(STDERR_FILENO, strerror(errno));
	ft_putstr(STDERR_FILENO, "\n");
}
