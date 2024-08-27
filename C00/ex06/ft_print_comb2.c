/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:57:04 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/02 20:45:57 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int		first_nmb;
	int		second_nmb;

	first_nmb = 0;
	while (first_nmb <= 98)
	{
		second_nmb = first_nmb + 1;
		while (second_nmb <= 99)
		{
			write(1, &((char){'0' + first_nmb / 10}), 1);
			write(1, &((char){'0' + first_nmb % 10}), 1);
			write(1, " ", 1);
			write(1, &((char){'0' + second_nmb / 10}), 1);
			write(1, &((char){'0' + second_nmb % 10}), 1);
			second_nmb++;
			if (!(first_nmb == 98))
				write(1, ", ", 2);
		}
		first_nmb++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
