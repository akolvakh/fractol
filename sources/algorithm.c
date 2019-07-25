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
	int i;

	ai->y = -1;
	while (++ai->y < HGT)
	{
		ai->x = -1;
		while (++ai->x < WDT)
		{
			ai->new_x = 1.5 * (ai->x - WDT / 2) / (ai->zoom * WDT / 2) + ai->mvx;
			ai->new_y = (ai->y - HGT / 2) / (ai->zoom * HGT / 2) + ai->mvy;
			init_formula(ai);
			i = -1;
			while (++i < ai->itr && ((ai->n_re * ai->n_re + ai->n_im * ai->n_im) < 4))
				formula_fractol(flag, ai);
			if (i < ai->itr)
				render_color(render_gradient(ai->x, ai->y,
						(i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_color(BLACK, ai->x, ai->y, ai);
		}
	}
}

void			algo_julia(t_dataset *ai)
{
	int i;

	ai->y = -1;
	while (++ai->y < HGT)
	{
		ai->x = -1;
		while (++ai->x < WDT)
		{
			ai->n_re = 1.5 * (ai->x - WDT / 2) / (ai->zoom * WDT / 2) + ai->mvx;
			ai->n_im = (ai->y - HGT / 2) / (ai->zoom * HGT / 2) + ai->mvy;
			i = -1;
			while (++i < ai->itr && ((ai->n_re * ai->n_re + ai->n_im) < 4))
				formula_fractol(JULIA, ai);
			if (i < ai->itr)
				render_color(render_gradient(ai->x, ai->y,
					(i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_color(BLACK, ai->x, ai->y, ai);
		}
	}
}
