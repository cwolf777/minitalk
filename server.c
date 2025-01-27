/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:01 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/27 16:57:14 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int signo, siginfo_t *info, void *context)
{
	static int				i = 0;
	int						pid;
	static unsigned char	c = 0;

	(void)context;
	pid = info->si_pid;
	c |= (signo == SIGUSR1);
	if (i < 7)
	{
		c <<= 1;
		i++;
	}
	else
	{
		if (signo == SIGUSR1)
			c <<= 1; // Letztes Bit verschieben, falls SIGUSR1
		ft_printf("Test\n");
		// if (c == '\0')
		// {
		// 	//Beenden des Prozesses 
		// }
		ft_putchar_fd(c, 1);
		c = 0;
		//kill?
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("My PID: %d\n", getpid());
	s_sigaction.__sigaction_u.__sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
