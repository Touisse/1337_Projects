/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:47 by ytouisse          #+#    #+#             */
/*   Updated: 2022/10/25 18:10:25 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getsize(int N)
{
	long	n;
	int		size;

	n = N;
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size = 1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_get_string(char *str, long n, int size)
{
	int	d;
	int	i;

	str[size] = '\0';
	i = size - 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		d = n % 10;
		str[i] = d + '0';
		i--;
		n /= 10;
	}
	if (i == 0)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int N)
{
	long	n;
	int		size;
	char	*str;

	n = N;
	size = getsize(n);
	if (N == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		return (str[0] = '0', str[1] = '\0', str);
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (ft_get_string(str, n, size));
}
