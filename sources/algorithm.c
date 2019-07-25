/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:10 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:12 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			algo_general(int flag, t_dataset *ai)
{
	ai->y = -1;
	while (++ai->y < HGT)
	{
		ai->x = -1;
		while (++ai->x < WDT)
		{
			ai->new_x = 1.5 * (ai->x - WDT / 2) / (ai->zoom * WDT / 2) + ai->crd_x;
			ai->new_y = (ai->y - HGT / 2) / (ai->zoom * HGT / 2) + ai->crd_y;
			init_formula(ai);
			ai->i = -1;
			while (++ai->i < ai->itr)
			{
				formula_fractol(flag, ai);
				if ((ai->def_x * ai->def_x + ai->def_y * ai->def_y) > 4)
					break ;
			}
			if (ai->i < ai->itr)
				render_image(render_color(ai->x, ai->y,
						(ai->i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_image(BLACK, ai->x, ai->y, ai);
		}
	}
}

void			algo_julia(t_dataset *ai)
{
	ai->y = -1;
	while (++ai->y < HGT)
	{
		ai->x = -1;
		while (++ai->x < WDT)
		{
			ai->def_x = 1.5 * (ai->x - WDT / 2) / (ai->zoom * WDT / 2) + ai->crd_x;
			ai->def_y = (ai->y - HGT / 2) / (ai->zoom * HGT / 2) + ai->crd_y;
			ai->i = -1;
			while (++ai->i < ai->itr)
			{
				formula_fractol(JULIA, ai);
				if ((ai->def_x * ai->def_x + ai->def_y) > 4)//
					break ;
			}
			if (ai->i < ai->itr)
				render_image(render_color(ai->x, ai->y,
					(ai->i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_image(BLACK, ai->x, ai->y, ai);
		}
	}
}
