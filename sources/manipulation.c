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

void	scale(int a, int x, int y, t_dataset *data) //объеденить в одну функцию
{
	x = x - WDT / 2;
	y = y - HGT / 2;
	data->x2 = ((data->x - x) - WDT) / ((double)HGT * 2);
	data->y2 = ((data->y - y) - HGT) / (((double)WDT * 2) + y);
	if (a == 1)
		data->zoom = data->zoom / pow(1.005, 50);//
	else
		data->zoom = data->zoom * pow(1.005, 50);//
	data->m_x = data->m_x - data->x2;
	data->m_y = data->m_y - data->y2;


}

int		motion(int x, int y, t_dataset *data)
{
	if (x > 0 && y > 0 && x < WDT && y < HGT)
	{
		if ((data->fractol == JULIA || data->fractol == 6) && data->movemouse == 1)//juliacubed
		{
			data->k = ((x - data->x) - WDT) / (((double)HGT * 2) + data->y);
			data->l = ((y + data->y) - HGT) / ((double)WDT * 2);
			render_scene(data);
		}
	}
	return (0);
}
