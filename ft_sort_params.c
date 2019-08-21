/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luchennn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:20:55 by luchennn          #+#    #+#             */
/*   Updated: 2019/07/17 20:30:35 by luchennn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_strswap(char **s1, char **s2);
void	ft_print_params(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char **argv)
{
	int		i;
	int		swaps;

	swaps = 1;
	i = 1;
	while (swaps)
	{
		swaps = 0;
		while (argv[i + 1])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_strswap(&argv[i], &argv[i + 1]);
				swaps++;
			}
			i++;
		}
		i = 1;
	}
	ft_print_params(argc - 1, argv);
	return (0);
}

void	ft_strswap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_print_params(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argc)
	{
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_putchar('\n');
		argc--;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
	}
	return (0);
}
