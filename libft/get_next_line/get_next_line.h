/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:34:59 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/21 15:52:06 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *s);
int		ft_strchr_check(const char *s, int c);
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t dstsize);
char	*ft_allocate_rest_str(char *rest_str);

#endif