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
	ai->old_x = ai->def_x;
	ai->old_y = (c == TRICORN) ? ai->def_y * -1 :  ai->def_y;
	if (c == JULIA)
	{
		ai->def_x = ai->old_x * ai->old_x - ai->old_y * ai->old_y + ai->pos_x;
		ai->def_y = 2 * ai->old_x * ai->old_y + ai->pos_y;
	}
	else if (c == MANDEL || c == TRICORN)
	{
		ai->def_x = ai->old_x * ai->old_x - ai->old_y * ai->old_y + ai->new_x;
		ai->def_y = 2 * ai->old_x * ai->old_y + ai->new_y;
	}
	else if (c == MANDELCUBED)
	{
		ai->def_x = (ai->old_x * ai->old_x * ai->old_x) -
			(ai->old_y * ai->old_x * ai->old_y) -
			(2 * ai->old_x * ai->old_y * ai->old_y) + ai->new_x;
		ai->def_y = (2 * ai->old_x * ai->old_x * ai->old_y) -
			(ai->old_y * ai->old_y * ai->old_y) + ai->new_y;
	}
	else if (c == SHIP)
	{
		ai->def_x = ai->old_x * ai->old_x - ai->old_y * ai->old_y + ai->new_x;
		ai->def_y = fabs(2 * ai->old_x * ai->old_y) + ai->new_y;//fabs?
	}
}

void	formula_scale(int flag, int x, int y, t_dataset *ai)//тут теперь расчитать попадание в точку и все так, как нужно
{
	x = x - WDT / 2;
	y = y - HGT / 2;
	ai->scale_x = ((ai->x - x) - WDT) / ((double)HGT * 2);
	ai->scale_y = ((ai->y - y) - HGT) / (((double)WDT * 2) + y);
	ai->zoom = (flag == 1) ? ai->zoom / pow(1.005, 50) : ai->zoom * pow(1.005, 50);// /1.3
	ai->crd_x = ai->crd_x - ai->scale_x;
	ai->crd_y = ai->crd_y - ai->scale_y;
}

int		formula_motion(int x, int y, t_dataset *ai)
{
	if (x > 0 && y > 0 && x < WDT && y < HGT)
	{
		if ((ai->fractol == JULIA) && ai->movemouse == 1)//|| ai->fractol == 6
		{
			ai->pos_x = ((x - ai->x) - WDT) / (((double)HGT * 2) + ai->y);
			ai->pos_y = ((y + ai->y) - HGT) / ((double)WDT * 2);
			render_scene(ai);
		}
	}
	return (0);
}
