/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:45:22 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/17 14:40:21 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_separator(char symbol, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (symbol == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			counter++;
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (counter);
}

char	*fill_result(char *str, char *charset)
{
	int		i;
	int		length;
	char	*word;

	length = 0;
	while (!is_separator(str[length], charset) && str[length] != '\0')
		length++;
	word = (char *)malloc((length + 1) * 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && !is_separator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split_result(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word;
	int		i;

	result = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (result == NULL || str == NULL || charset == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			result[word] = fill_result(&str[i], charset);
			if (result[word] == NULL)
				return (free_split_result(result), NULL);
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
			word++;
		}
		else
			i++;
	}
	result[word] = 0;
	return (result);
}
