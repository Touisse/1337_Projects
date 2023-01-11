/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:17:28 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/10 16:30:55 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_fractol(int ac, char const **av)
{
	int	fractol;

	fractol = 0;
	if (ac != 2)
		return (-1);

	if (ft_strcmp(av[1], "mandelbrot") == 0)
		fractol = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		fractol = 1;
	else if (ft_strcmp(av[1], "julia") != 0)
		fractol = -1;
	else if (ft_strcmp(av[1], "mandelbrot") != 0)
		fractol = -1;
	else if (fractol < 0 || fractol > 2)
		return (-1);
	return (fractol);
}

int	main(int ac, char const **av)
{
	t_env	*env;
	int		fractol;

	fractol = valid_fractol(ac, av);
	if (fractol == -1)
	{
		ft_putstr_fd("Invalid Parameter!\n", 2);
		return (1);
	}
	env = init_env(fractol);
	draw_env(env);
	mlx_hook(env->win, 2, 1L << 0, &handle_keyboard, env);
	mlx_hook(env->win, 17, 1L << 2, &kill, env);
	// mlx_hook(env->win, 6, 1L << 6, change_julia_c, env);
	// mlx_mouse_hook(env->win, handle_mouse, env);
	mlx_loop(env->mlx);
	return (0);
}
