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
			data->newre = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->movex;
			data->newim = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->movey;
			data->i = -1;
			while (++data->i < data->iteration)
			{
				formula_julia(data);
				if ((data->newre * data->newre + data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
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
			data->pr = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->movex;
			data->pi = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->movey;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				formula_mandelcubed(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
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
			data->pr = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->movex;
			data->pi = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->movey;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				formula_mandel(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
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
			data->pr = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->movex;
			data->pi = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->movey;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				formula_ship(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
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
			data->pr = 1.5 * (data->x - WDT / 2) /
				(0.5 * data->zoom * WDT) + data->movex;
			data->pi = (data->y - HGT / 2) /
				(0.5 * data->zoom * HGT) + data->movey;
			init_formula(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				formula_tricorn(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}
