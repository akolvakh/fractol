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

void	init_julia(t_dataset *data)
{
	data->m_x = 0;
	data->m_y = 0;
	data->k = -0.7;
	data->l = 0.27015;
	data->itr = 30;
	data->zoom = 0.5;
}

void	init_mandel(t_dataset *data)
{
	data->m_x = 0;
	data->m_y = 0;
	data->itr = 15;
	data->zoom = 0.5;
}

void	init_ship(t_dataset *data)
{
	data->m_x = 0;
	data->m_y = 0;
	data->itr = 15;
	data->zoom = 0.5;
}

void	init_formula(t_dataset *data)
{
	data->old_l = 0;
	data->oldr_k = data->old_l;
	data->new_l = data->oldr_k;
	data->new_k = data->new_l;
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
	if (data->fractol == MANDELCUBED)
		init_mandel(data);
}
