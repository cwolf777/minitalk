/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:44:58 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/24 09:45:31 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base16(const char *input, int i, va_list args)
{
	int	token;
	int	check_error;
	int	count;

	token = 0;
	count = 0;
	if (input[i] == 'x' || input[i] == 'X')
	{
		if (input[i] == 'X')
			token = 1;
		check_error = ft_printhexa(va_arg(args, unsigned int), token);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	return (count);
}
