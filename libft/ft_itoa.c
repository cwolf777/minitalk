/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:37:55 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:00:51 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_length(int n);
static void		fill_str(char *str, int length, int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		is_negative;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = n * (-1);
		is_negative = 1;
	}
	length = count_length(n) + is_negative;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (is_negative == 1)
		str[0] = '-';
	str[length] = '\0';
	length = length - 1;
	fill_str(str, length, n);
	return (str);
}

static int	count_length(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	fill_str(char *str, int length, int n)
{
	while (n > 0)
	{
		str[length] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
}
