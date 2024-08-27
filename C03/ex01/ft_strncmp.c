/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:37:16 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/05 09:17:31 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
	{
		if (s1[i] == '\0' && s2[i] != '\0')
			return (s1[i] - s2[i]);
		if (s1[i] != '\0' && s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (0);
}
