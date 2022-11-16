/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:57:42 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/07 16:57:42 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format(const char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c')
	length += ft_putchar(va_arg(args, int));
	else if (format == 's')
	length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	length += ft_putstr("0x") + ft_put_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
	length += put_nbr_base(va_arg(args, int), "0123456789", (char)format);
	else if (format == 'u')
	length += ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
	length += put_nbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				format);
	else if (format == 'X')
	length += put_nbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				format);
	return (length);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;
	int		size;

	size = ft_strlen(str);
	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			length += write(1, &str[i], 1);
		else if (i + 1 < size && str[i] == '%' && str[i + 1] == '%')
			length += write(1, &str[i++], 1);
		else if (i + 1 < size && str[i] == '%' && str[i + 1] != '%')
			length += get_format(str[i++ + 1], args);
	i++;
	}
	va_end(args);
	return (length);
}
