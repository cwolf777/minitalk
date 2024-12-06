/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:01 by cwolf             #+#    #+#             */
/*   Updated: 2024/12/06 11:02:16 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	static	get_byte(int bit);
void	static	convert_to_char(int *byte);
void	static	char_into_string(char character);

void	static	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		get_byte(0);
	}
	else if (signum == SIGUSR2)
	{
		get_byte(1);
	}
}

void	static	get_byte(int bit)
{
	static int	byte[8];
	static int	bit_index = 0;
	int			i;

	byte[bit_index] = bit;
	bit_index++;
	if (bit_index == 8)
	{
		convert_to_char(byte);
		bit_index = 0;
		i = 0;
		while (i < 8)
		{
			byte[i] = 0;
			i++;
		}
	}
}

void	static	convert_to_char(int *byte)
{
	int		i;
	int		ascii_val;
	char	character;

	ascii_val = 0;
	i = 0;
	while (i < 8)
	{
		ascii_val = ascii_val * 2 + byte[i];
		i++;
	}
	character = (char)ascii_val;
	char_into_string(character);
}

void	static	char_into_string(char character)
{
	static char	*string;
	char		*c;

	if (character == '\0')
	{
		ft_printf("%s\n", string);
		string = "";
		return ;
	}
	c = malloc(sizeof(char) * 2);
	if (c == NULL)
		return ;
	c[0] = character;
	c[1] = '\0';
	if (string == NULL)
	{
		string = ft_strdup("");
	}
	string = ft_strjoin(string, c);
	free(c);
}

int	main(void)
{
	ft_printf("My PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
