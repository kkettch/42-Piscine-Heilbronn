/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:27:36 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/05 09:26:00 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		dst_symbols_size;
	unsigned int		src_symbols_size;

	dst_symbols_size = 0;
	src_symbols_size = 0;
	while (dest[dst_symbols_size] != '\0')
		dst_symbols_size++;
	while (src[src_symbols_size] != '\0')
		src_symbols_size++;
	if (size <= dst_symbols_size)
		return (size + src_symbols_size);
	i = 0;
	while (i < (size - dst_symbols_size - 1))
	{
		dest[dst_symbols_size + i] = src[i];
		i++;
	}
	dest[dst_symbols_size + i] = '\0';
	return (dst_symbols_size + src_symbols_size);
}
