/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:42:39 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/23 15:06:13 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	int	count;
	int	check_error;

	count = 0;
	if (n >= 10)
	{
		check_error = ft_putnbr_fd((n / 10), fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	check_error = ft_putchar_fd(n % 10 + '0', fd);
	if (check_error == -1)
		return (-1);
	count += check_error;
	return (count);
}
