/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:31 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/01 10:54:30 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	answer;

	if (n < 0)
	{
		answer = 'N';
	}
	else
	{
		answer = 'P';
	}
	write(1, &answer, 1);
}
