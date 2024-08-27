/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:56:50 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/03 09:11:44 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		return_value;

	i = 0;
	return_value = 1;
	if (*str == '\0')
		return (1);
	while (*(str + i) != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (return_value);
}
