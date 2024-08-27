/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:56:32 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/06 19:19:40 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_unique(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_size(char *base)
{
	int		c;

	c = 0;
	while (base[c] != '\0')
	{
		if (base[c] == '+' || base[c] == '-' || base[c] == ' ')
			return (0);
		c++;
	}
	return (c);
}

int	is_symbols_correct(char *str, char *base)
{
	int		i;
	int		j;
	int		str_size;
	int		flag;

	i = 0;
	str_size = 0;
	flag = 1;
	while (str[i] != '\0' && flag)
	{
		j = 0;
		flag = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				flag = 1;
				str_size++;
			}
			j++;
		}
		i++;
	}
	return (str_size);
}

int	calculate_result(int str_size, int base_size, char *str, char *base)
{
	int		i;
	int		j;
	int		flag;
	int		result;

	i = 0;
	result = 0;
	while ((str_size - 1) >= 0)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		flag = 0;
		while (flag < str_size - 1)
		{
			j = j * base_size;
			flag++;
		}
		result = result + j;
		str_size--;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		count_minus_sign;
	int		base_size;
	int		str_size;
	int		result;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	count_minus_sign = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count_minus_sign++;
		str++;
	}
	base_size = count_size(base);
	if (!(is_unique(base)) || base_size <= 1)
		return (0);
	str_size = is_symbols_correct(str, base);
	if (str_size == 0)
		return (0);
	result = calculate_result(str_size, base_size, str, base);
	if (count_minus_sign % 2 == 1)
		result = -1 * result;
	return (result);
}
