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
	ai->moveX = 0;
	ai->moveY = 0;
	ai->re = -0.7;
	ai->im = 0.27015;
	ai->itr = 30;
	ai->zoom = 0.5;
	ai->color = 1;
}

void	init_mandel(t_dataset *ai)
{
	ai->moveX = 0;
	ai->moveY = 0;
	ai->itr = 15;
	ai->zoom = 0.5;
	ai->color = 1;
}

void	init_ship(t_dataset *ai)
{
	ai->moveX = 0;
	ai->moveY = 0;
	ai->itr = 15;
	ai->zoom = 0.5;
	ai->color = 1;
}

void	init_formula(t_dataset *ai)
{
	ai->oldIm = 0;
	ai->oldRe = ai->oldIm;
	ai->newIm = ai->oldRe;
	ai->newRe = ai->newIm;
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
