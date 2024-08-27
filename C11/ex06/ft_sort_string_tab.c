/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:27:41 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:12 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	position_changed = 1;
	while (position_changed)
	{
		position_changed = 0;
		i = 0;
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

void	ft_sort_string_tab(char **tab)
{
	int	counter;

	counter = 0;
	while (tab[counter])
		counter++;
	sort_string_array(counter, tab);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int size = 5;
// 	char *array[] = {" ", "5", "[", "a", "A", NULL};
// 	ft_sort_string_tab(array);
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%s\n", array[i]);
// 	}
// 	return (0);
// }