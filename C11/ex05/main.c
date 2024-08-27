/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mcmurov@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:48:48 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/16 09:11:49 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
int		do_sum(int a, int b);
int		do_minus(int a, int b);
int		do_div(int a, int b);
int		do_multi(int a, int b);
int		do_mod(int a, int b);

int	is_valid(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strcmp(argv[2], "+") != 0 && ft_strcmp(argv[2], "-") != 0
		&& ft_strcmp(argv[2], "/") != 0 && ft_strcmp(argv[2], "*") != 0
		&& ft_strcmp(argv[2], "%") != 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (ft_strcmp(argv[2], "/") == 0 && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (ft_strcmp(argv[2], "%") == 0 && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int	calculate(int a, int b, char *sign)
{
	int	(*operator[5])(int, int);
	int	result;

	result = 0;
	operator[0] = &do_sum;
	operator[1] = &do_minus;
	operator[2] = &do_div;
	operator[3] = &do_multi;
	operator[4] = &do_mod;
	if (ft_strcmp(sign, "+") == 0)
		result = operator[0](a, b);
	if (ft_strcmp(sign, "-") == 0)
		result = operator[1](a, b);
	if (ft_strcmp(sign, "/") == 0)
		result = operator[2](a, b);
	if (ft_strcmp(sign, "*") == 0)
		result = operator[3](a, b);
	if (ft_strcmp(sign, "%") == 0)
		result = operator[4](a, b);
	return (result);
}

int	main(int argc, char **argv)
{
	int	first_number;
	int	second_number;
	int	result;

	if (!is_valid(argc, argv))
		return (0);
	first_number = ft_atoi(argv[1]);
	second_number = ft_atoi(argv[3]);
	result = calculate(first_number, second_number, argv[2]);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
