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
	ai->oldRe = ai->newRe;
	ai->oldIm = (c == TRICORN) ? ai->newIm * -1 :  ai->newIm;
	if (c == JULIA)
	{
		ai->newRe = ai->oldRe * ai->oldRe - ai->oldIm * ai->oldIm + ai->re;
		ai->newIm = 2 * ai->oldRe * ai->oldIm + ai->im;
	}
	else if (c == MANDEL || c == TRICORN)
	{
		ai->newRe = ai->oldRe * ai->oldRe - ai->oldIm * ai->oldIm + ai->new_x;
		ai->newIm = 2 * ai->oldRe * ai->oldIm + ai->new_y;
	}
	else if (c == MANDELCUBED)
	{
		ai->newRe = (ai->oldRe * ai->oldRe * ai->oldRe) -
			(ai->oldIm * ai->oldRe * ai->oldIm) -
			(2 * ai->oldRe * ai->oldIm * ai->oldIm) + ai->new_x;
		ai->newIm = (2 * ai->oldRe * ai->oldRe * ai->oldIm) -
			(ai->oldIm * ai->oldIm * ai->oldIm) + ai->new_y;
	}
	else if (c == SHIP)
	{
		ai->newRe = ai->oldRe * ai->oldRe - ai->oldIm * ai->oldIm + ai->new_x;
		ai->newIm = fabs(2 * ai->oldRe * ai->oldIm) + ai->new_y;//fabs?
	}
}

void	formula_scale(int flag, int x, int y, t_dataset *ai)//тут теперь расчитать попадание в точку и все так, как нужно
{
	x = x - WDT / 2;
	y = y - HGT / 2;
	ai->scale_x = ((ai->x - x) - WDT) / ((double)HGT * 2);
	ai->scale_y = ((ai->y - y) - HGT) / (((double)WDT * 2) + y);
	ai->zoom = (flag == 1) ? ai->zoom / pow(1.005, 50) : ai->zoom * pow(1.005, 50);// /1.3
	ai->moveX = ai->moveX - ai->scale_x;
	ai->moveY = ai->moveY - ai->scale_y;
}

int		formula_motion(int x, int y, t_dataset *ai)
{
	//if (x > 0 && y > 0 && x < WDT && y < HGT)
//	{
		if ((ai->fractol == JULIA) && ai->movemouse == 1)//|| ai->fractol == 6
		{
			ai->re = ((x - ai->x) - WDT) / (((double)HGT * 2) + ai->y);
			ai->im = ((y + ai->y) - HGT) / ((double)WDT * 2);
		}
	//}
	render_scene(ai);
	return (0);
}
