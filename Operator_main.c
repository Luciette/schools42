/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchennn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:15:37 by luchennn          #+#    #+#             */
/*   Updated: 2019/07/28 17:40:16 by luchennn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		(*g_f[5]) (int x, int y) = {add, subtract, multiply, divide, mod};
char	*g_operators[5] = {"+", "-", "*", "/", "%"};
t_list	*g_stack = NULL;
char	**g_words = NULL;
char	**g_queue;

char	**convert_expr(char *str)
{
	int		i;
	int		j;
	int		order;
	t_list	*current;

	i = -1;
	j = 0;
	g_words = make_word_array(g_words, str);
	current = g_stack;
	g_queue = malloc(sizeof(char **) * ft_count_words(str) + 1);
	while (g_words[++i] != NULL)
	{
		if (g_words[i][0] >= '0' && g_words[i][0] <= '9')
			g_queue[j++] = g_words[i];
		if (g_words[i][0] == '(')
			ft_list_push_front(&g_stack, g_words[i]);
		if (g_words[i][0] == ')')
			j = eval_brackets(current, j);
		if ((order = check_order(g_words[i][0])))
			j = eval_operator(current, g_words[i], order, j);
		current = g_stack;
	}
	dump_stack(j);
	return (g_queue);
}

int		eval_expr(char *str)
{
	int		i;
	int		j;
	int		numbers[128];
	char	**expression;
	int		op;

	i = 0;
	j = 0;
	expression = convert_expr(str);
	while (expression[j])
	{
		if (check_expression(expression[j]) == 1)
			numbers[i++] = ft_atoi(expression[j++]);
		else if (check_expression(expression[j]) == 2)
		{
			op = ft_get_in_array(g_operators, expression[j++]);
			i -= 2;
			numbers[i] = ft_do_op(numbers[i], numbers[i + 1], g_f[op]);
			numbers[i++ + 1] = 0;
		}
	}
	return (numbers[0]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
