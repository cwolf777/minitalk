/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:26:58 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/23 14:51:56 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;
	int	check_error;

	count = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		check_error = write(fd, &s[i], 1);
		if (check_error == -1)
			return (-1);
		i++;
		count++;
	}
	return (count);
}
