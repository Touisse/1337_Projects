/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:06 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/08 21:31:18 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		get_format(const char format, va_list args);
int		put_nbr_base(long long nbr, char *base, char type);
int		ft_put_unsigned(unsigned int n);
int		ft_put_ptr(unsigned long long ptr);
int		ft_putstr(char *str);
int		ft_putchar(int c);
size_t	ft_strlen(const char *str);

#endif