/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:51:08 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/27 15:35:17 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *str);

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
	}
	else
	{
		ft_printf("Sytaxerror! Please insert ./client <PID> <String>\n");
		exit(1);
	}
	send_signals(pid, str);
}

void	send_signals(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str; // 00101010
		str++;
		while (i > 0)
		{
			i--;
			if (c >> i & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
				kill(pid, SIGUSR2);
			usleep(50); //?
		}
	}
	//00000000 sschicken
}

