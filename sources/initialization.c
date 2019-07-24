/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:25:57 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:25:58 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
	data->cre = -0.7;
	data->cim = 0.27015;
}

void	init_mandel(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
}

void	init_ship(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
}

void	init_main(t_dataset *data)
{
	if (data->fractol == JULIA)
		init_julia(data);
	if (data->fractol == MANDEL)
		init_mandel(data);
	if (data->fractol == SHIP)
		init_ship(data);
	if (data->fractol == TRICORN)
		init_mandel(data);
	if (data->fractol == JULIACUBED)
		init_julia(data);
	if (data->fractol == MANDELCUBED)
		init_mandel(data);
}
