/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:30:21 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/09 14:26:39 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, t_env *env)
{
	t_complex	z;
	int			iteration;

	z.re = 0;
	z.im = 0;
	iteration = 0;
	while (iteration < env->iterations && modulus(z) <= 2)
	{
		z = add(multiply(z, z), c);
		iteration++;
	}
	if (iteration == env->iterations)
		return (iteration);
	return (iteration);
}

int	julia(t_complex z, t_env *env)
{
	int			iteration;
	t_complex	c;

	c = env->julia_c;
	iteration = 0;
	while (iteration < env->iterations && modulus(z) <= 2)
	{
		z = add(multiply(z, z), c);
		iteration++;
	}
	if (iteration == env->iterations)
		return (iteration);
	return (iteration);
}
