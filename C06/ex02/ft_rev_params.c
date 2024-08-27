/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:59:31 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/07 16:34:40 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*funciton_name;

	i = argc - 1;
	funciton_name = NULL;
	while (i != 0)
	{
		funciton_name = argv[i];
		j = 0;
		while (funciton_name[j] != '\0')
		{
			write(1, funciton_name + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
