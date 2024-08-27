/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:04:40 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/04 19:13:02 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		start;

	start = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[start] != '\0')
	{
		i = 0;
		while (str[start + i] == to_find[i] && str[start + i] != '\0')
		{
			if (to_find[i + 1] == '\0')
				return (str + start);
			i++;
		}
		start++;
	}
	return (NULL);
}
