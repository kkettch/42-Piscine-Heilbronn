/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:35:45 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 15:33:55 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// int	main(void)
// {
// 	char	str[13] = "Hello, world!";
// 	char	*dest1;
// 	char	*dest2;

// 	dest1 = ft_strdup(str);
// 	printf("%s\n", dest1);
// 	dest2 = ft_strdup(str);
// 	printf("%s\n", dest2);
// 	return (0);
// }