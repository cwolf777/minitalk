/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:18:54 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:02:15 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;
	char	x;

	str = (char *) b;
	x = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		str[i] = x;
		i++;
	}
	return (b);
}
