/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:33:47 by ytouisse          #+#    #+#             */
/*   Updated: 2022/10/25 19:52:44 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	src_len;
	char			*dest;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (src_len < start)
	{
		dest = malloc(sizeof(char) * 1);
		if (!(dest))
			return (NULL);
		return (dest[0] = '\0', dest);
	}
	len = min(src_len - start, len);
	dest = (char *)malloc(sizeof(*s) * (len + 1));
	if (!(dest))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest[i] = '\0', dest);
}
