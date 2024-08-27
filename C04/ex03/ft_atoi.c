/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:11:53 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/06 19:22:19 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		count_minus_sign;
	int		result;

	count_minus_sign = 0;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count_minus_sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (count_minus_sign % 2 == 1)
		result = -1 * result;
	return (result);
}
