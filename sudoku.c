/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchennn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:07:03 by luchennn          #+#    #+#             */
/*   Updated: 2019/07/20 22:07:16 by luchennn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jms.h"

int		sudoku_solver(int grid[9][9])
{
	int row;
	int col;
	int num;

	num = 1;
	if (!(has_empty_spaces(grid, &row, &col)))
		return (1);
	while (num <= 9)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (sudoku_solver(grid))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int grid[9][9])
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			PUTNUM(grid[row][col]);
			if (col != 8)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int		main(int argc, char **argv)
{
	int row;
	int col;
	int grid[9][9];
	int cluecount;

	if (argc != 10)
		return (ft_error());
	row = -1;
	cluecount = 0;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (argv[row + 1][col] > '0' && argv[row + 1][col] <= '9')
			{
				grid[row][col] = argv[row + 1][col] - '0';
				cluecount++;
			}
			else
				grid[row][col] = 0;
		}
	}
	(sudoku_solver(grid) && cluecount >= 17) ? print_grid(grid) : ft_error();
	return (0);
}
