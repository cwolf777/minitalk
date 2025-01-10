/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:39:54 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:05:04 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		length;

	a = (char) c;
	length = 0;
	while (s[length])
	{
		length++;
	}
	while (length >= 0)
	{
		if (s[length] == a)
			return ((char *)(s + length));
		length--;
	}
	return (NULL);
}
