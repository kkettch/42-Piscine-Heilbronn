/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:02:00 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/08 18:52:01 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		size_dest;

	size_dest = 0;
	while (*(dest + size_dest) != '\0')
		size_dest++;
	i = 0;
	while (*(src + i) != '\0')
	{
		dest[size_dest + i] = *(src + i);
		i++;
	}
	*(dest + size_dest + i) = '\0';
	return (dest);
}
