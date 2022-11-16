/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:32:35 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/04 15:22:34 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(const char *str, char c)
{
	int	i;
	int	boool;

	i = 0;
	boool = 0;
	while (*str)
	{
		if (*str != c && boool == 0)
		{
			boool = 1;
			i++;
		}
		else if (*str == c)
			boool = 0;
		str++;
	}
	return (i);
}

static char	**ft_free(char **dest, int i)
{
	while (i >= 0)
	{
		free(dest[i]);
		i--;
	}
	free(dest);
	return (NULL);
}

int	c_lenght(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k] != c)
	{
		if (s[k] == '\0')
			break ;
		k++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	if (s == NULL)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	j = 0;
	i = 0;
	dest[c_words(s, c)] = NULL;
	while (i < c_words(s, c))
	{
		while (s[j] == c)
			j++;
		dest[i] = ft_substr(s, j, c_lenght(s + j, c));
		if (dest[i] == NULL)
			return (ft_free(dest, i));
		i++;
		j += c_lenght(s + j, c);
	}
	return (dest);
}
