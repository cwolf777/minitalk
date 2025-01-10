/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:09:46 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:04:07 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	joined_length;
	size_t	s1_len;

	i = 0;
	joined_length = ft_strlen(s1) + ft_strlen(s2);
	s1_len = ft_strlen(s1);
	str = malloc(joined_length + 1);
	if (str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (i < joined_length)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
