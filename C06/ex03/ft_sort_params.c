/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:35:56 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 13:16:56 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	sort_string_array(int argc, char *argv[])
{
	int		i;
	char	*name;
	int		position_changed;

	i = 1;
	position_changed = 1;
	while (position_changed)
	{
		position_changed = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				position_changed = 1;
				name = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = name;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*name;

	sort_string_array(argc, argv);
	i = 1;
	name = NULL;
	while (i < argc)
	{
		name = argv[i];
		j = 0;
		while (name[j] != '\0')
		{
			write(1, name + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
