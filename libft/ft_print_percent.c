/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:28:50 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/25 07:45:41 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	int	check_error;
	int	count;

	count = 0;
	check_error = ft_putchar_fd('%', 1);
	if (check_error == -1)
		return (-1);
	count += check_error;
	return (count);
}
