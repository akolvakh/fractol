/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:38 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:39 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scale_up(int x, int y, t_dataset *data)
{
	x -= WDT / 2;
	y -= HGT / 2;
	data->x2 = ((data->x - x) - WDT) / ((double)HGT * 2);
	data->y2 = ((data->y - y) - HGT) / (((double)WDT * 2) + y);
	data->zoom *= pow(1.001, 70);
	data->movex -= data->x2;
	data->movey -= data->y2;
}

void	scale_down(int x, int y, t_dataset *data)
{
	x -= WDT / 2;
	y -= HGT / 2;
	data->x2 = ((data->x - x) - WDT) / ((double)HGT * 2);
	data->y2 = ((data->y - y) - HGT) / (((double)WDT * 2) + y);
	data->zoom /= pow(1.001, 70);
	data->movex -= data->x2;
	data->movey -= data->y2;
}

int		motion(int x, int y, t_dataset *data)
{
	if (x > 0 && y > 0 && x < WDT && y < HGT)
	{
		if ((data->fractol == 1 || data->fractol == 6) && data->movemouse == 1)
		{
			data->clickx = x;
			data->clicky = y;
			data->defre = ((data->clickx - data->x) -
				WDT) / (((double)HGT * 2) + data->y);
			data->defim = ((data->clicky + data->y) -
				HGT) / ((double)HGT * 2);
			render_scene(data);
		}
	}
	return (0);
}
