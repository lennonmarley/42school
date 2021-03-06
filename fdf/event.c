/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 01:15:43 by yismail           #+#    #+#             */
/*   Updated: 2016/04/24 16:48:25 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_key_funct(int keycode, t_projdots *env)
{
	if (keycode == 29 && env->event.alt <= 50)
		env->event.alt += 1;
	if (keycode == 25 && env->event.alt > 0)
		env->event.alt -= 1;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if ((keycode == 24) && (env->event.zoom <= 15))
		env->event.zoom++;
	if (keycode == 27 && env->event.zoom >= -10)
		env->event.zoom--;
	if (keycode == 126)
		env->event.move_y--;
	if (keycode == 125)
		env->event.move_y++;
	if (keycode == 123)
		env->event.move_x--;
	if (keycode == 124)
		env->event.move_x++;
	if (keycode == 1 && env->event.rotate_y <= 5)
		env->event.rotate_y++;
	if (keycode == 13 && env->event.rotate_y >= -5)
		env->event.rotate_y--;
	mlx_clear_window(env->mlx, env->win);
	ft_pixel_put(env->tmp, env->mlx, env->win, *env);
	return (0);
}

void		ft_set_event(t_projdots *env)
{
	env->event.zoom = 1;
	env->event.alt = 1;
	env->event.move_y = 1;
	env->event.move_x = 1;
	env->event.rotate_y = 3;
	env->event.z_min = 100;
	env->event.z_max = -100;
	env->event.alt = 0;
}

int			colors(int zo, t_projdots *spc)
{
	t_color	col_min;
	t_color	col_max;
	t_color	col_fin;
	int		int_col_fin;

	col_min.r = 250;
	col_min.g = 100;
	col_min.b = 250;
	col_max.r = 120;
	col_max.g = 150;
	col_max.b = 150;
	if (spc->event.z_max - spc->event.z_min == 0)
		return (0xA83044);
	col_fin.r = ((col_max.r - col_min.r)
	/ (spc->event.z_max - spc->event.z_min));
	col_fin.g = ((col_max.g - col_min.g)
	/ (spc->event.z_max - spc->event.z_min));
	col_fin.b = ((col_max.b - col_min.b)
	/ (spc->event.z_max - spc->event.z_min));
	int_col_fin = color_to_int(col_fin);
	if (int_col_fin < 0)
		return (zo * (-int_col_fin));
	if (zo != 0)
		return (zo * (int_col_fin));
	return (0xA83044);
}
