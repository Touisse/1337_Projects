/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:32:46 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/07 19:34:37 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_complex	multiply(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return (c);
}

double	modulus(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
