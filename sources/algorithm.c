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
			ai->p_k = 1.5 * (ai->x - WDT / 2) /
				(0.5 * ai->zoom * WDT) + ai->m_x;
			ai->p_l = (ai->y - HGT / 2) / (0.5 * ai->zoom * HGT) + ai->m_y;
			init_formula(ai);
			ai->i = -1;
			while (++ai->i < ai->itr)
			{
				formula_fractol(flag, ai);
				if ((ai->new_k * ai->new_k + ai->new_l * ai->new_l) > 4)
					break ;
			}
			if (ai->i < ai->itr)
				render_image(render_color(ai->x, ai->y,
						(ai->i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_image(200, ai->x, ai->y, ai);
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
			ai->new_k = 1.5 * (ai->x - WDT / 2) /
				(0.5 * ai->zoom * WDT) + ai->m_x;
			ai->new_l = (ai->y - HGT / 2) / (0.5 * ai->zoom * HGT) + ai->m_y;
			ai->i = -1;
			while (++ai->i < ai->itr)
			{
				formula_fractol(JULIA, ai);
				if ((ai->new_k * ai->new_k + ai->new_l) > 4)
					break ;
			}
			if (ai->i < ai->itr)
				render_image(render_color(ai->x, ai->y,
					(ai->i * ai->color), ai), ai->x, ai->y, ai);
			else
				render_image(0x000000, ai->x, ai->y, ai);
		}
	}
}
