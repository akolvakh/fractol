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
	ai->oldr_k = ai->new_k;
	ai->old_l = ai->new_l;
	if (c == JULIA)
	{
		ai->new_k = ai->oldr_k * ai->oldr_k - ai->old_l * ai->old_l + ai->k;
		ai->new_l = 2 * ai->oldr_k * ai->old_l + ai->l;
	}
	else if (c == MANDEL)
	{
		ai->new_k = ai->oldr_k * ai->oldr_k - ai->old_l * ai->old_l + ai->p_k;
		ai->new_l = 2 * ai->oldr_k * ai->old_l + ai->p_l;
	}
	else if (c == MANDELCUBED)
	{
		ai->new_k = (ai->oldr_k * ai->oldr_k * ai->oldr_k) -
			(ai->old_l * ai->oldr_k * ai->old_l) -
			(2 * ai->oldr_k * ai->old_l * ai->old_l) + ai->p_k;
		ai->new_l = (2 * ai->oldr_k * ai->oldr_k * ai->old_l) -
			(ai->old_l * ai->old_l * ai->old_l) + ai->p_l;
	}
	else if (c == SHIP)
	{
		ai->new_k = ai->oldr_k * ai->oldr_k - ai->old_l * ai->old_l + ai->p_k;
		ai->new_l = fabs(2 * ai->oldr_k * ai->old_l) + ai->p_l;
	}
}

void	formula_tricorn(t_dataset *ai)
{
	ai->oldr_k = ai->new_k;
	ai->old_l = ai->new_l * -1;
	ai->new_k = ai->oldr_k * ai->oldr_k - ai->old_l * ai->old_l + ai->p_k;
	ai->new_l = 2 * ai->oldr_k * ai->old_l + ai->p_l;
}

void	formula_scale(int a, int x, int y, t_dataset *ai)
{
	x = x - WDT / 2;
	y = y - HGT / 2;
	ai->x2 = ((ai->x - x) - WDT) / ((double)HGT * 2);
	ai->y2 = ((ai->y - y) - HGT) / (((double)WDT * 2) + y);
	if (a == 1)
		ai->zoom = ai->zoom / pow(1.005, 50);
	else
		ai->zoom = ai->zoom * pow(1.005, 50);
	ai->m_x = ai->m_x - ai->x2;
	ai->m_y = ai->m_y - ai->y2;
}

int		formula_motion(int x, int y, t_dataset *ai)
{
	if (x > 0 && y > 0 && x < WDT && y < HGT)
	{
		if ((ai->fractol == JULIA || ai->fractol == 6) && ai->movemouse == 1)
		{
			ai->k = ((x - ai->x) - WDT) / (((double)HGT * 2) + ai->y);
			ai->l = ((y + ai->y) - HGT) / ((double)WDT * 2);
			render_scene(ai);
		}
	}
	return (0);
}
