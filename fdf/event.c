/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 01:15:43 by yismail           #+#    #+#             */
/*   Updated: 2016/04/07 07:00:51 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     my_key_funct(int keycode, proj_dots *spc)
{
    ft_putstr("the key is ");
    ft_putnbr(keycode);
    ft_putchar('\n');
    if (keycode == 53)
        exit(EXIT_SUCCESS);

    if (keycode == 24)
        spc->event.zoom++;
    if (keycode == 27)
        spc->event.zoom--;	
    return (0);
}

void    ft_set_event(proj_dots *env)
{
    env->event.zoom = 1;
    env->event.alt = 1;
    env->event.move = 1;
    env->event.rotate = 1;
}

void	color (proj_dots *spc)
{
	int r = 0;
	int v = 255;
	int b = 255;
	int cpt;

	cpt = 0;
	
		cpt = (spc->zo);
	while (cpt > 0)
	{
		if (b > 95)
			b = (b - 95);
		else
			b = 0;
		if (b == 0 && r <= 160)
			r = (r + 95);
		if (b == 0 && r >= 160 && v > 95)
			v = (v - 95);
		if (v < 95)
			v = 0;
		cpt--;
	}
	spc->color_new = ((r&0x0ff)<<16)|((v&0x0ff)<<8)|(b&0x0ff);
}
