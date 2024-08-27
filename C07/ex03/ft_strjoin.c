/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:34:10 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 18:51:23 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_sep_length(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

char	*add_sep(int change_result, char *sep, char *result)
{
	int		i;

	i = 0;
	while (sep[i] != '\0')
	{
		result[change_result] = sep[i];
		i++;
		change_result++;
	}
	return (result);
}

int	count_total_length(int size, int total_length, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		i++;
	}
	return (total_length);
}

char	*write_result(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	j;
	int	change_result;

	i = 0;
	change_result = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[change_result] = strs[i][j];
			change_result++;
			j++;
		}
		if ((i != size - 1))
		{
			result = add_sep(change_result, sep, result);
			change_result = change_result + count_sep_length(sep);
		}
		i++;
	}
	result[change_result] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_length;

	if (size == 0)
	{
		result = (char *)(malloc(1));
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_length = count_sep_length(sep) * ((size - 1));
	total_length = total_length + count_total_length(size, total_length, strs);
	result = (char *)malloc(total_length + 1);
	result = write_result(size, strs, sep, result);
	return (result);
}

// int	main(void)
// {
// 	char *strs[] = {"hello", "everybody", "123456"};
// 	char *result;
//  	int size = sizeof(strs) / sizeof(strs[0]);
// 	result = ft_strjoin(size, strs, ",  ");
// 	printf("%s\n", result);
// 	return (0);
// }