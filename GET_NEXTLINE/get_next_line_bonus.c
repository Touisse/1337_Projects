/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:35:50 by ytouisse          #+#    #+#             */
/*   Updated: 2022/11/16 12:54:13 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*keep_str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 10240)
		return (0);
	keep_str[fd] = ft_read_to_keep_str(fd, keep_str[fd]);
	if (!keep_str[fd])
		return (NULL);
	if (!*keep_str[fd])
	{
		free(keep_str[fd]);
		return (keep_str[fd] = 0);
	}
	line = ft_get_line(keep_str[fd]);
	keep_str[fd] = ft_new_keep_str(keep_str[fd]);
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
