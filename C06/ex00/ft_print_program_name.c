/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:59:59 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 11:30:05 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*funciton_name;

	i = 0;
	funciton_name = NULL;
	if (argc >= 0)
		funciton_name = argv[0];
	while (funciton_name[i] != '\0')
	{
		write(1, funciton_name + i, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
