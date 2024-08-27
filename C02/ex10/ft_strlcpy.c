/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:31:40 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/13 20:14:16 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		string_length;

	string_length = 0;
	i = 0;
	while (src[string_length] != '\0')
		string_length++;
	if (size == 0)
		return (string_length);
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (string_length);
}

#include <stdio.h>

int main() {
    char src[] = "Hello, World!";
    char dst[9];

    size_t copied = ft_strlcpy(dst, src, sizeof(dst));

    printf("Destination: %s\n", dst);
    printf("Length of source: %zu\n", copied);

    return 0;
}
