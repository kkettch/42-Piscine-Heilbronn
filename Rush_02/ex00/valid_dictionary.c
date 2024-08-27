/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:27:13 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/18 17:47:13 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_file(int index);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);

int	check_line(char *splitted_line)
{
	int	i;

	i = 0;
	if (splitted_line[i] == ' ')
		return (0);
	if (splitted_line[i] < '0' || splitted_line[i] > '9')
		return (0);
	while (splitted_line[i] >= '0' && splitted_line[i] <= '9')
		i++;
	while (splitted_line[i] == ' ')
		i++;
	if (splitted_line[i] != ':')
		return (0);
	while (splitted_line[i] == ' ')
		i++;
	if (splitted_line[i] != '\0')
		return (1);
	return (0);
}

int	check_dictionary(char *file)
{
	int		i;
	int		index;
	char	**lines;

	index = open(file, O_RDONLY);
	if (index == -1)
		return (0);
	lines = ft_split(get_file(index), " :\n");
	i = 0;
	while (lines[i])
	{
		if (check_line(lines[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
