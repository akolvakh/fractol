/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:27 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:28 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_dataset *ai)
{
	ai->m_x = 0;
	ai->m_y = 0;
	ai->k = -0.7;
	ai->l = 0.27015;
	ai->itr = 30;
	ai->zoom = 0.5;
}

void	init_mandel(t_dataset *ai)
{
	ai->m_x = 0;
	ai->m_y = 0;
	ai->itr = 15;
	ai->zoom = 0.5;
}

void	init_ship(t_dataset *ai)
{
	ai->m_x = 0;
	ai->m_y = 0;
	ai->itr = 15;
	ai->zoom = 0.5;
}

void	init_formula(t_dataset *ai)
{
	ai->old_l = 0;
	ai->oldr_k = ai->old_l;
	ai->new_l = ai->oldr_k;
	ai->new_k = ai->new_l;
}

void	init_main(t_dataset *ai)
{
	if (ai->fractol == JULIA)
		init_julia(ai);
	if (ai->fractol == MANDEL)
		init_mandel(ai);
	if (ai->fractol == SHIP)
		init_ship(ai);
	if (ai->fractol == TRICORN)
		init_mandel(ai);
	if (ai->fractol == MANDELCUBED)
		init_mandel(ai);
}
