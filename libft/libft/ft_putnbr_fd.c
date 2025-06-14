/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:35:47 by cwolf             #+#    #+#             */
/*   Updated: 2025/06/13 15:56:50 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;
	int		check_error;

	count = 0;
	nb = (long) n;
	if (nb < 0)
	{
		check_error = ft_putchar_fd('-', fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
		nb = nb * (-1);
	}
	if (nb >= 10)
	{
		check_error = ft_putnbr_fd((nb / 10), fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	check_error = ft_putchar_fd(nb % 10 + '0', fd);
	if (check_error == -1)
		return (-1);
	return (count + check_error);
}
