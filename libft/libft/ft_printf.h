/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:25:25 by cwolf             #+#    #+#             */
/*   Updated: 2024/10/25 09:10:25 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_toupper(int a);
size_t	ft_strlen(const char *s);
int		ft_count_length(int n);
int		ft_unsigned_putnbr_fd(unsigned int n, int fd);
int		ft_printf(const char *input, ...);
int		ft_printhexa(unsigned long int number, int token);
int		ft_print_base10(const char *input, int i, va_list args);
int		ft_print_base16(const char *input, int i, va_list args);
int		ft_print_characters(const char *input, int i, va_list args);
int		ft_print_percent(void);
int		ft_print_pointer(va_list args);

#endif