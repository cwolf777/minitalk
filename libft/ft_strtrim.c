/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:58:36 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/18 18:05:08 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	set_check(char c, char const *set);
static	int	trim_start(char const *s1, char const *set);
static	int	trim_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}

static	int	trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && set_check(s1[i], set) == 1)
	{
		i++;
	}
	return (i);
}

static	int	trim_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && set_check(s1[i], set) == 1)
	{
		i--;
	}
	return (i);
}

static	int	set_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
