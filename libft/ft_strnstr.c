/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:54:37 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:04:59 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && i < len)
	{
		x = 0;
		while (haystack[x] == needle[x] && haystack[x] != '\0' && x + i < len)
		{
			x++;
		}
		if (needle[x] == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
