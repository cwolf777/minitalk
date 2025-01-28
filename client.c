/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:51:08 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/28 10:04:04 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signals(int pid, char c);

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (str[i] != '\0')
		{
			send_signals(pid, str[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Sytaxerror! Please insert ./client <PID> <String>\n");
		exit(1);
	}
}

static void	send_signals(int pid, char c)
{
	int		i;

	i = 8;
	while (i > 0)
	{
		i--;
		if (c >> i & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}
