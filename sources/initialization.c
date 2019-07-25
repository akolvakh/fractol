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

void	init_general(t_dataset *ai)
{
	ai->mvx = 0;
	ai->mvy = 0;
	ai->itr = 15;
	ai->zoom = 0.5;
	ai->color = 1;
}

void	init_julia(t_dataset *ai)
{
	ai->mvx = 0;
	ai->mvy = 0;
	ai->re = -0.7;
	ai->im = 0.27015;
	ai->itr = 30;
	ai->zoom = 0.5;
	ai->color = 1;
}

void	init_formula(t_dataset *ai)
{
	ai->o_im = 0;
	ai->o_re = ai->o_im;
	ai->n_im = ai->o_re;
	ai->n_re = ai->n_im;
}

void	init_main(t_dataset *ai)
{
	if (ai->fractol == MANDEL
	|| ai->fractol == SHIP
	|| ai->fractol == TRICORN
	|| ai->fractol == MANDELCUBED)
		init_general(ai);
	else if (ai->fractol == JULIA)
		init_julia(ai);
}
