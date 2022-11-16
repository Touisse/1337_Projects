/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:46:19 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/05 19:26:03 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*p;

	p = (unsigned char *)dest;
	while (count > 0)
	{
		*p = (unsigned char)c;
		p++;
		count--;
	}
	if (dest == NULL)
		return (NULL);
	return (dest);
}
