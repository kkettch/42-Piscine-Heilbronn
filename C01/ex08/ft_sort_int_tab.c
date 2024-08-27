/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:23:08 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/01 16:19:33 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int		position_changed;
	int		i;
	int		tmp;

	position_changed = 1;
	while (position_changed)
	{
		position_changed = 0;
		i = 0;
		while (i < size - 1)
		{
			if (*(tab + i) > *(tab + i + 1))
			{
				position_changed = 1;
				tmp = *(tab + i);
				*(tab + i) = *(tab + i + 1);
				*(tab + i + 1) = tmp;
			}
			i++;
		}
	}
}
