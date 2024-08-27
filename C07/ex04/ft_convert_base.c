/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:46:21 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/09 09:30:20 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	count_size(char *base);
int	is_unique(char *base);

int	count_length(int nbr, char *base)
{
	int	size;
	int	base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	size = 0;
	if (nbr <= 0)
		size = 1;
	while (nbr)
	{
		nbr /= base_size;
		size++;
	}
	return (size);
}

void	ft_recursive(int middle_result, char *base, char *result, int *p)
{
	int	base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	if (middle_result == -2147483648)
	{
		result[(*p)++] = '-';
		ft_recursive((-1 * (middle_result / base_size)), base, result, p);
		result[(*p)++] = base[2147483648 % base_size];
		return ;
	}
	if (middle_result < 0)
	{
		result[(*p)++] = '-';
		middle_result = -1 * middle_result;
	}
	if (middle_result >= base_size)
		ft_recursive(middle_result / base_size, base, result, p);
	result[(*p)++] = base[middle_result % base_size];
}

char	*ft_itoa_base(int middle_result, char *base)
{
	char	*result;
	int		length;
	int		position;

	length = count_length(middle_result, base);
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	position = 0;
	if (middle_result == 0)
		result[position++] = base[0];
	else
		ft_recursive(middle_result, base, result, &position);
	result[position] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		middle_result;
	char	*result;

	if (!is_unique(base_from) || !is_unique(base_to))
		return (NULL);
	if (count_size(base_from) <= 1 || count_size(base_to) <= 1)
		return (NULL);
	middle_result = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(middle_result, base_to);
	return (result);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_convert_base("42", "0123456789", "5");
// 	printf("%s\n", result);
// 	return (0);
// }