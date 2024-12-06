/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:01 by cwolf             #+#    #+#             */
/*   Updated: 2024/12/05 17:21:38 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	static	in_string(int bit);

void	static	signal_handler(int signum, char *byte)
{
	if (signum == SIGUSR1)
	{
		in_string(0);
	}
	else if (signum == SIGUSR2)
	{
		in_string(1);
	}
}

void	static	in_string(int bit)
{
	char	byte[8];
	int		i;

	i = 0;
	if (bit == 0)
	{
		byte[i] = '0';
	}
	else if (bit == 1)
	{
		byte[i] = '0';
	}
	i++;
	ft_printf("String: %s\n", byte);
}

int	main(void)
{
	ft_printf("My PID: %d", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}

// char bin_to_ascii(const char *bin)
// {
// int i;
// int decimal = 0;

// // Über die 8 Bits iterieren und den Dezimalwert berechnen
// for (i = 0; i < 8; i++) {
// 	decimal = decimal * 2 + (bin[i] - '0'); // '0' wird subtrahiert, um von char zu int zu konvertieren
// }
