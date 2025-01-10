/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:40:39 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/24 09:45:27 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base10(const char *input, int i, va_list args)
{
	int	count;
	int	check_error;

	count = 0;
	if (input[i] == 'u')
	{
		check_error = ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	else if (input[i] == 'd' || input[i] == 'i')
	{
		check_error = ft_putnbr_fd(va_arg(args, int), 1);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	return (count);
}
