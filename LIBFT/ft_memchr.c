/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:49:08 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/05 19:26:52 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	const char		*find;

	find = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (find[i] == (char)c)
			return ((void *)&find[i]);
		i++;
	}
	return (NULL);
}
