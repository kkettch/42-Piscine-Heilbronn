/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:20:54 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:18 by mchmurov         ###   ########.fr       */
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

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *array[] = {"0", "123", "0", NULL};
// 	printf("%d\n", ft_any(array, &ft_atoi));
// 	return (0);
// }
