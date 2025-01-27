/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:32:38 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/19 09:01:16 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (dest_len + src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i < dstsize - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < dstsize)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
