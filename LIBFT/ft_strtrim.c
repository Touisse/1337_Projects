/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:59:31 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/04 14:09:45 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = s1;
	end = s1 + len - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	if (start == s1 + len)
		return (ft_strdup(""));
	while (*end && ft_strchr(set, *end))
		end--;
	return (ft_substr(start, 0, end - start + 1));
}
