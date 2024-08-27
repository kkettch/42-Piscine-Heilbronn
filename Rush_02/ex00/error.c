/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:03:58 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/17 14:40:22 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	input_error(void)
{
	write(1, "Error\n", 6);
	return ;
}

void	dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return ;
}
