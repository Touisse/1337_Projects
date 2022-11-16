/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:47:07 by ytouisse          #+#    #+#             */
/*   Updated: 2022/10/25 18:36:32 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	if (char_dest == NULL && char_src == NULL)
		return (NULL);
	if (char_dest > char_src)
	{
		while (n--)
			char_dest[n] = char_src[n];
	}
	else
		ft_memcpy(char_dest, char_src, n);
	return (char_dest);
}
