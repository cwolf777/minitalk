/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:11:32 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/25 09:28:18 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inside_function(int count, unsigned long int number,
				int check_error, int token);

int	ft_printhexa(unsigned long int number, int token)
{
	int		count;
	int		check_error;

	count = 0;
	check_error = 0;
	if (number == 0)
	{
		check_error = ft_putchar_fd('0', 1);
		if (check_error == -1)
			return (-1);
		return (1);
	}
	if (number >= 16)
	{
		check_error = ft_printhexa(number / 16, token);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	count = inside_function(count, number, check_error, token);
	return (count);
}

static int	inside_function(int count, unsigned long int number,
		int check_error, int token)
{
	char	x;

	if (number % 16 < 10)
	{
		check_error = ft_putchar_fd((number % 16) + '0', 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	else
	{
		x = ((number % 16) - 10 + 'a');
		if (token == 1)
			check_error = ft_putchar_fd(ft_toupper(x), 1);
		else
			check_error = ft_putchar_fd(x, 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	return (count);
}
