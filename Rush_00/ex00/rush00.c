/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchmurov <mchmurov@student.42.heilbronn.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:44:10 by mchmurov          #+#    #+#             */
/*   Updated: 2024/08/03 13:10:20 by mchmurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		line;
	int		column;

	if (x <= 0 || y <= 0)
		return ;
	line = 1;
	while (line <= y)
	{
		column = 1;
		while (column <= x)
		{
			if ((line == 1 || line == y) && (column == 1 || column == x))
				ft_putchar('o');
			if ((line == 1 || line == y) && !(column == 1 || column == x))
				ft_putchar('-');
			if (!(line == 1 || line == y) && (column == 1 || column == x))
				ft_putchar('|');
			if (!(line == 1 || line == y) && !(column == 1 || column == x))
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		line++;
	}
}
