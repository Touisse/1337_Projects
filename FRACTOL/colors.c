/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:45:20 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/09 15:31:03 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, t_env *env)
{
	int	red;
	int	green;
	int	blue;

	if (iter == env->iterations)
		return (0);
	red = env->color_base * (cos((double)iter) + 1);
	green = env->color_base * (sin((double)iter) + 1);
	blue = env->color_base * (1 - cos((double)iter));
	return ((red << 16) | (green << 8) | blue);
}
