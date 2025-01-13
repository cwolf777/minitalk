/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:51:08 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/13 10:36:49 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	get_ascii(int pid, char *str);
static	void	convert_to_binary(int nbr, int pid);
static	void	send_to_server(int *arr, int pid);

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		get_ascii(pid, str);
	}
	else
	{
		ft_printf("Sytaxerror! Please insert ./client <PID> <String>\n");
		exit(1);
	}
}

static	void	get_ascii(int pid, char *str)
{
	int	i;
	int	nbr;

	i = 0;
	while (str[i] != '\0')
	{
		nbr = (int)str[i];
		convert_to_binary(nbr, pid);
		i++;
	}
	convert_to_binary(0, pid);
	return ;
}

static	void	convert_to_binary(int nbr, int pid)
{
	int	arr[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		arr[i] = 0;
		i--;
	}
	i = 7;
	while (nbr >= 1)
	{
		arr[i] = nbr % 2;
		nbr = nbr / 2;
		i--;
	}
	send_to_server(arr, pid);
}

static	void	send_to_server(int *arr, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (arr[i] == 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(5000);
		i++;
	}
}
