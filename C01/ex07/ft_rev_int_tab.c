/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:28:25 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/01 16:14:45 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		start_of_array;
	int		end_of_array;
	int		tmp;

	start_of_array = 0;
	end_of_array = size - 1;
	while (start_of_array < end_of_array)
	{
		tmp = *(tab + start_of_array);
		*(tab + start_of_array) = *(tab + end_of_array);
		*(tab + end_of_array) = tmp;
		start_of_array++;
		end_of_array--;
	}
}
