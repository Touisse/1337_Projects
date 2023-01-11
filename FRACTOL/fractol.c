/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:21:16 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/11 16:06:46 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_env_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_env	*init_env(int fractol)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->height = 700;
	env->width = 800;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Fractol");
	reset(env);
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	env->iterations = 80;
	env->julia_c = init(0, 0);
	env->is_julia_active = false;
	if (fractol == 0)
		env->f = mandelbrot;
	else if (fractol == 1)
	{
		env->f = julia;
		env->is_julia_active = true;
	}
	env->color_base = 0xff0505;
	return (env);
}

void	draw_env(t_env	*env)
{
	int	i;
	int	j;

	i = 0 ;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			my_env_pixel_put(&(env->img), j, i, get_color(
					env->f(remap(j, i, env), env), env));
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}
