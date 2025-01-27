/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:50:22 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/24 09:50:42 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_characters(const char *input, int i, va_list args)
{
	int	count;
	int	check_error;

	count = 0;
	if (input[i] == 'c')
	{
		check_error = ft_putchar_fd(va_arg(args, int), 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	else if (input[i] == 's')
	{
		check_error = ft_putstr_fd(va_arg(args, char *), 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	return (count);
}
