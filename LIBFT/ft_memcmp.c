/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:48:16 by ytouisse          #+#    #+#             */
/*   Updated: 2022/10/27 16:02:52 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*p;
	unsigned const char	*q;

	p = str1;
	q = str2;
	while (n > 0)
	{
		if (*p != *q)
			return (*p - *q);
		n--;
		p++;
		q++;
	}
	return (0);
}
