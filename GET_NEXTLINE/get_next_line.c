/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:48:32 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/10 14:48:32 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*keep_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	keep_str = ft_read_to_keep_str(fd, keep_str);
	if (!keep_str)
		return (NULL);
	if (!*keep_str)
	{
		free(keep_str);
		return (keep_str = 0);
	}
	line = ft_get_line(keep_str);
	keep_str = ft_new_keep_str(keep_str);
	return (line);
}

char	*ft_read_to_keep_str(int fd, char *keep_str)
{
	char	*buff;
	int		readed;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(keep_str, '\n') && readed != 0)
	{
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
		{
			free(buff);
			if (readed == -1)
			{
				free(keep_str);
				keep_str = NULL;
			}
			return (keep_str);
		}
		buff[readed] = '\0';
		keep_str = ft_strjoin(keep_str, buff);
	}
	free(buff);
	return (keep_str);
}

char	*ft_new_keep_str(char *keep_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (keep_str[i] && keep_str[i] != '\n')
		i++;
	if (!keep_str[i])
	{
		free(keep_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ((ft_strlen(keep_str) - i) + 1));
	if (!str)
		return (free(keep_str), NULL);
	i++;
	j = 0;
	while (keep_str[i])
		str[j++] = keep_str[i++];
	str[j] = '\0';
	free(keep_str);
	return (keep_str = str, keep_str);
}

char	*ft_get_line(char *keep_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!keep_str[i])
		return (NULL);
	while (keep_str[i] && keep_str[i] != '\n')
		i++;
	if (keep_str[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (keep_str[i] && keep_str[i] != '\n')
	{
		str[i] = keep_str[i];
		i++;
	}
	if (keep_str[i] == '\n')
	{
		str[i] = keep_str[i];
		i++;
	}
	return (str[i] = '\0', str);
}
