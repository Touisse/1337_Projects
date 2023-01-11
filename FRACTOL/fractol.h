/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:20:28 by ytouisse          #+#    #+#             */
/*   Updated: 2023/01/10 16:36:23 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

# define KEY_ESCAPE			53
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DEL			117
# define KEY_Z				6
# define KEY_N				45
# define KEY_R				15
# define KEY_S				1
# define KEY_C				8


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_data		img;
	double		re_start;
	double		re_end;
	double		im_start;
	double		im_end;
	double		width;
	double		height;
	int			iterations;
	t_complex	julia_c;
	int			(*f)(struct s_complex, struct s_env *);
	bool		is_julia_active;
	int			color_base;
}	t_env;

int				valid_fractol(int ac, char const **av);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *n);
t_complex		init(double re, double im);
t_complex		add(t_complex a, t_complex b);
t_complex		multiply(t_complex a, t_complex b);
double			modulus(t_complex z);
int				mandelbrot(t_complex c, t_env *env);
int				julia(t_complex z, t_env *env);
void			draw_env(t_env	*env);
t_env			*init_env(int fractol);
void			my_env_pixel_put(t_data *data, int x, int y, int color);
t_complex		remap(double x, double y, t_env *env);
int				get_color(int iter, t_env *env);
void			reset(t_env *env);
int				kill(t_env *env);
int				ft_strcmp(const char *s1, const char *s2);
int				handle_keyboard(int key, t_env *s_env);
#endif