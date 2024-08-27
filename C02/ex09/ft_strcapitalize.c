/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:36:35 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/03 18:06:40 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (flag == 1 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if (flag == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		flag = (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9');
		i++;
	}
	return (str);
}
