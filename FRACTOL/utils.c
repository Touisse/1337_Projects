/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:26:00 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/10 16:37:33 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *n)
{
	int		ans;
	int		sign;
	char	*nb;

	ans = 0;
	sign = 1;
	nb = (char *)n;
	while (*nb == ' ' || *nb == '\n' || *nb == '\f'
		|| *nb == '\r' || *nb == '\t' || *nb == '\v')
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			sign = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		ans *= 10;
		ans += *nb - '0';
		nb++;
	}
	return (sign * ans);
}

t_complex	remap(double x, double y, t_env *env)
{
	double		new_range_x;
	double		new_range_y;
	t_complex	new_val;

	new_range_x = env->re_end - env->re_start;
	new_range_y = env->im_end - env->im_start;
	new_val.re = x * (new_range_x / env->width) + env->re_start;
	new_val.im = y * (new_range_y / env->height) + env->im_start;
	return (new_val);
}
