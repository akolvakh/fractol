/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:21 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:22 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	formula_fractol(int c, t_dataset *ai)
{
	ai->o_re = ai->n_re;
	ai->o_im = (c == TRICORN) ? ai->n_im * -1 :  ai->n_im;
	if (c == JULIA)
	{
		ai->n_re = ai->o_re * ai->o_re - ai->o_im * ai->o_im + ai->re;
		ai->n_im = 2 * ai->o_re * ai->o_im + ai->im;
	}
	else if (c == MANDEL || c == TRICORN)
	{
		ai->n_re = ai->o_re * ai->o_re - ai->o_im * ai->o_im + ai->new_x;
		ai->n_im = 2 * ai->o_re * ai->o_im + ai->new_y;
	}
	else if (c == MANDELCUBED)
	{
		ai->n_re = (ai->o_re * ai->o_re * ai->o_re) -
			(ai->o_im * ai->o_re * ai->o_im) -
			(2 * ai->o_re * ai->o_im * ai->o_im) + ai->new_x;
		ai->n_im = (2 * ai->o_re * ai->o_re * ai->o_im) -
			(ai->o_im * ai->o_im * ai->o_im) + ai->new_y;
	}
	else if (c == SHIP)
	{
		ai->n_re = ai->o_re * ai->o_re - ai->o_im * ai->o_im + ai->new_x;
		ai->n_im = fabs(2 * ai->o_re * ai->o_im) + ai->new_y;
	}
}

void	formula_scale(int flag, int x, int y, t_dataset *ai)
{
	x = x - WDT / 2;
	y = y - HGT / 2;
	ai->scale_y = ((ai->y - y) - HGT) / (((double)WDT * 2) + y);
	ai->scale_x = ((ai->x - x) - WDT) / ((double)HGT * 2);
	ai->zoom = (flag == 1) ? ai->zoom / pow(1.005, 50) : ai->zoom * pow(1.005, 50);
	ai->mvy = ai->mvy - ai->scale_y;
	ai->mvx = ai->mvx - ai->scale_x;
}

int		formula_motion(int x, int y, t_dataset *ai)
{
	if (ai->mvmouse == 1)
	{
		ai->re = ((x - ai->x) - WDT) / (((double)HGT * 2) + ai->y);
		ai->im = ((y + ai->y) - HGT) / ((double)WDT * 2);
	}
	render_scene(ai);
	return (0);
}
