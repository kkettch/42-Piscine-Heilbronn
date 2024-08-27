/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:14:15 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 10:35:48 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	if ((nb == 0) || (nb == 1))
		return (1);
	if (nb < 0)
		return (0);
	result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
