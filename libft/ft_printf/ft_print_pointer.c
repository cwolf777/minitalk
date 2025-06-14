/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:31:55 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/25 07:43:58 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	int	count;
	int	check_error;
	int	token;

	count = 0;
	token = 0;
	check_error = ft_putstr_fd("0x", 1);
	if (check_error == -1)
		return (-1);
	count += check_error;
	check_error = ft_printhexa(va_arg(args, unsigned long), token);
	if (check_error == -1)
		return (-1);
	count += check_error;
	return (count);
}
