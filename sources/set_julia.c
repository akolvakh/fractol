/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:28:04 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:28:05 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		bonus_juliacubed(t_dataset *data)//formula
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = (data->oldre * data->oldre * data->oldre) -
		(data->oldim * data->oldim * data->oldre) -
		(2 * data->oldre * data->oldim * data->oldim) + data->cre;
	data->newim = (3 * data->oldre * data->oldre * data->oldim) -
		(data->oldim * data->oldim * data->oldim) + data->cim;
}

void			calculation_juliacubed(t_dataset *data)//algo
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->newre = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->newim = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			data->i = -1;
			while (++data->i < data->iteration)
			{
				bonus_juliacubed(data);
				if ((data->newre * data->newre + data->newim) > 4)
					break ;//
			}
			if (data->i < data->iteration)
				render_image(render_color(data->x, data->y,
						(data->i * data->color), data), data->x, data->y, data);
			else
				render_image(0x000000, data->x, data->y, data);
		}
	}
}

static void		mandatory_julia(t_dataset *data)//formula
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre -
			data->oldim * data->oldim + data->cre;
	data->newim = 2 * data->oldre * data->oldim + data->cim;
}

void			calculation_julia(t_dataset *data)//algo
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->newre = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->newim = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			data->i = -1;
			while (++data->i < data->iteration)
			{
				mandatory_julia(data);
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
