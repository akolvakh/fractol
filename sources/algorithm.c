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

void			algo_julia(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HGT)
	{
		data->x = -1;
		while (++data->x < WDT)
		{
			data->new_k = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->m_x;
			data->new_l = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->m_y;
			data->i = -1;
			while (++data->i < data->itr)
			{
				formula_julia(data);
				if ((data->new_k * data->new_k + data->new_l) > 4)
					break ;
			}
			if (data->i < data->itr)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(0x000000, data->x, data->y, data);
		}
	}
}

void			algo_mandelcubed(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HGT)
	{
		data->x = -1;
		while (++data->x < WDT)
		{
			data->p_k = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->m_x;
			data->p_l = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->m_y;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->itr)
			{
				formula_mandelcubed(data);
				if ((data->new_k * data->new_k + data->new_l * data->new_l) > 4)
					break ;
			}
			if (data->i < data->itr)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}

void			algo_mandel(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HGT)
	{
		data->x = -1;
		while (++data->x < WDT)
		{
			data->p_k = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->m_x;
			data->p_l = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->m_y;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->itr)
			{
				formula_mandel(data);
				if ((data->new_k * data->new_k + data->new_l * data->new_l) > 4)
					break ;
			}
			if (data->i < data->itr)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}

void			algo_ship(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HGT)
	{
		data->x = -1;
		while (++data->x < WDT)
		{
			data->p_k = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->m_x;
			data->p_l = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->m_y;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->itr)
			{
				formula_ship(data);
				if ((data->new_k * data->new_k + data->new_l * data->new_l) > 4)
					break ;
			}
			if (data->i < data->itr)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}

void			algo_tricorn(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HGT)
	{
		data->x = -1;
		while (++data->x < WDT)
		{
			data->p_k = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->m_x;
			data->p_l = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->m_y;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->itr)
			{
				formula_tricorn(data);
				if ((data->new_k * data->new_k + data->new_l * data->new_l) > 4)
					break ;
			}
			if (data->i < data->itr)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}
