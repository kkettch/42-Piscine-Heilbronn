/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:28:09 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:17 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	ft_atoi(char *str)
// {
// 	int		count_minus_sign;
// 	int		result;

// 	count_minus_sign = 0;
// 	result = 0;
// 	while (*str == ' ' || *str == '\t' || *str == '\n'
// 		|| *str == '\v' || *str == '\f' || *str == '\r')
// 		str++;
// 	while (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			count_minus_sign++;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9' && *str != '\0')
// 	{
// 		result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	if (count_minus_sign % 2 == 1)
// 		result = -1 * result;
// 	return (result);
// }

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// int	main(void)
// {
// 	int size = 5;
// 	char *array[] = {"0", "123", "1", "   ", "", NULL};
// 	printf("%d\n", ft_count_if(array, size, &ft_atoi));
// 	return (0);
// }
