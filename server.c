/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:38:01 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/10 22:05:37 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	get_byte(int bit);
static	void	convert_to_char(int *byte);
static	void	char_into_string(char character);

static	void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Test1\n");
		get_byte(0);
	}
	else if (signum == SIGUSR2)
	{
		get_byte(1);
	}
}

static	void	get_byte(int bit)
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

static	void	convert_to_char(int *byte)
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
	ft_printf("Test2\n");
	char_into_string(character);
}

static	void	char_into_string(char character)
{
	static char	*string;
	char		*c;
	char		*temp;

	if (character == '\0')
	{
		ft_printf("%s\n", string);
		free(string);
		string = NULL;
		return ;
	}
	c = malloc(sizeof(char) * 2);   //neue ft allokiere c, und joine string
	if (c == NULL)
	{
		free(string);
		string = NULL;
		return ;
	}
	c[0] = character;
	c[1] = '\0';
	if (string == NULL)
		temp = ft_strjoin("", c);
	else
	{
		temp = ft_strjoin(string, c);
		free(string);
	}
	free(c);
	if (!temp)
		exit(1);
	string = temp;
	ft_printf("Test3\n");
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
