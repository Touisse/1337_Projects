/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:55 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/08 20:21:33 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr_base(long long nbr, char *base, char type)
{
	int	d;
	int	lenght;

	lenght = 0;
	if (type == 'd' || type == 'i')
		d = 10;
	else
		d = 16;
	if (nbr < 0)
	{
		lenght += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > d - 1)
	{
		lenght += put_nbr_base(nbr / d, base, type);
		lenght += put_nbr_base(nbr % d, base, type);
	}
	else
		lenght += write(1, &base[nbr], 1);
	return (lenght);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	lenght;

	lenght = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[lenght])
	{
		write(1, &str[lenght], 1);
		lenght++;
	}
	return (lenght);
}

int	ft_put_unsigned(unsigned int n)
{
	int		lenght;
	char	c;

	lenght = 0;
	if (n > 9)
	{
		lenght += ft_put_unsigned(n / 10);
		lenght += ft_put_unsigned(n % 10);
	}
	else
	{
		c = n + '0';
		lenght += write(1, &c, 1);
	}
	return (lenght);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int		lenght;

	lenght = 0;
	if (ptr > 15)
	{
		lenght += ft_put_ptr(ptr / 16);
		lenght += ft_put_ptr(ptr % 16);
	}
	else
	{
		lenght += write(1, &"0123456789abcdef"[ptr], 1);
	}
	return (lenght);
}
