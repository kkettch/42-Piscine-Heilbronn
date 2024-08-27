/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:40:40 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 10:43:14 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if ((power) == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	if (power > 0)
		result = ft_recursive_power(nb, power - 1);
	result = result * nb;
	return (result);
}
