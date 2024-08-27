/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
ft_putchar('o')/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:13:34 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/03 14:58:49 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		l;
	int		c;

	if (x <= 0 || y <= 0)
		return ;
	l = 1;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((l == 1 && c == 1) || (l == y && c == x && c != 1 && y != 1))
				ft_putchar('/');
			else if ((c == x && c != 1 && l == 1) || (c == 1 && l == y))
				ft_putchar('\\');
			else if (!(l == 1 || l == y) && !(c == 1 || c == x))
				ft_putchar(' ');
			else
				ft_putchar('*');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
