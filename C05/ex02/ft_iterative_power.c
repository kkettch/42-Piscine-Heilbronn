/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:30:19 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 10:37:46 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if ((power) == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	i = 0;
	result = nb;
	while (i < power - 1)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
