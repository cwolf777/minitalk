/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:01 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/28 15:47:15 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int signo)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (signo == SIGUSR1);
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("My PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		pause();
	}
	return (0);
}
