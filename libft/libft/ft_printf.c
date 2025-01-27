/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:44:50 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/25 09:14:12 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_deligate(const char *input, int i, va_list args);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		check_error;

	count = 0;
	va_start(args, input);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
			check_error = ft_putchar_fd(input[i++], 1);
		else if (input[i] == '%')
		{
			i++;
			check_error = ft_deligate(input, i, args);
			i++;
		}
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	va_end(args);
	return (count);
}

static int	ft_deligate(const char *input, int i, va_list args)
{
	int	count;
	int	check_error;

	check_error = 0;
	count = 0;
	if (input[i] == 'c' || input[i] == 's')
		check_error = ft_print_characters(input, i, args);
	else if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u')
		check_error = ft_print_base10(input, i, args);
	else if (input[i] == 'x' || input[i] == 'X')
		check_error = ft_print_base16(input, i, args);
	else if (input[i] == 'p')
		check_error = ft_print_pointer(args);
	else if (input[i] == '%')
		check_error = ft_print_percent();
	if (check_error == -1)
		return (-1);
	count += check_error;
	return (count);
}
