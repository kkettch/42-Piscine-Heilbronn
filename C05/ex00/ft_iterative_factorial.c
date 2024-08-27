/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:31:55 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 10:43:02 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if ((nb == 0) || (nb == 1))
		return (1);
	if (nb < 0)
		return (0);
	result = 1;
	while (nb != 0)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}
