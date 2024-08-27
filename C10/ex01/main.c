/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:19:54 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/20 09:17:55 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(int output, char *str);
void	print_error_message(char *name);
void	read_terminal(void);
void	print_file(char *name);

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		read_terminal();
	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-") == 0)
			read_terminal();
		else
			print_file(argv[i]);
		i++;
	}
	return (0);
}
