/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:45:18 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/11 16:43:35 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keyboard(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
		kill(env);
	if (key == KEY_R)
		reset(env);
	return (0);
}

// int	handle_mouse(int key, int x, int y, t_env *env)
// {
// 	if (key == 4)
// 		zoom_in(env, x, y);
// 	if (key == 5)
// 		zoom_out(env, x, y);
// 	draw_env(env);
// 	return (0);
// }

int	kill(t_env *env)
{
	if (env->win != 0)
		free(env->win);
	if (env->img.img != 0)
		free(env->img.img);
	if (env->img.addr != 0)
		free(env->img.addr);
	if (env->mlx != 0)
		free(env->mlx);
	if (env != 0)
		free(env);
	exit(0);
	return (0);
}

void	reset(t_env *env)
{
	env->re_start = -2;
	env->re_end = 2;
	env->im_start = -2;
	env->im_end = 2;
}
