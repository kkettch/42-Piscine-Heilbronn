/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:58 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/13 10:22:57 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*copy;

	size = 0;
	while (src[size] != '\0')
		size++;
	i = 0;
	copy = (char *)malloc(size + 1);
	if (copy)
	{
		while (src[i] != '\0')
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
	{
		errno = ENOMEM;
		return (NULL);
	}
}

void	free_memory(struct s_stock_str *return_value)
{
	int	i;

	i = 0;
	while (i > 0)
	{
		free(return_value[i - 1].copy);
		i--;
	}
	free(return_value);
}

int	count_length(char *string)
{
	int	size_of_string;

	size_of_string = 0;
	while (string[size_of_string] != '\0')
		size_of_string++;
	return (size_of_string);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*return_value;
	int					i;

	return_value = (struct s_stock_str *)malloc((ac + 1) * (8 + 8 + 8));
	if (!return_value)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		return_value[i].size = count_length(av[i]);
		return_value[i].str = av[i];
		return_value[i].copy = ft_strdup(av[i]);
		if (!return_value[i].copy)
		{
			free_memory(return_value);
			return (NULL);
		}
		i++;
	}
	return_value[i].size = 0;
	return_value[i].str = 0;
	return_value[i].copy = 0;
	return (return_value);
}
