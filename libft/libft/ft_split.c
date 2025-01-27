/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:19:09 by cwolf             #+#    #+#             */
/*   Updated: 2024/12/09 16:40:01 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c);
static int		load_strings(char **arr, char const *s, char c);
static char		*malloc_str(int len, int i, char **arr);

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if (words == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	arr = (char **)malloc(sizeof (char *) * (words + 1));
	if (arr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	arr[words] = NULL;
	if (load_strings(arr, s, c) == 0)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] != c && (i == 0 || s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static	int	load_strings(char **arr, char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			arr[i] = malloc_str(len + 1, i, arr);
			if (arr[i] == NULL)
				return (0);
			ft_strlcpy(arr[i], s - len, len + 1);
			i++;
		}
	}
	return (1);
}

static char	*malloc_str(int len, int i, char **arr)
{
	char	*str;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
	{
		i = i - 1;
		while (i >= 0)
		{
			free(arr[i]);
			i--;
		}
		return (NULL);
	}
	return (str);
}
