/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:09 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:11 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoomin(int x, int y, t_dataset *data)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	data->x2 = ((data->x - x) - WIDTH) / ((double)HEIGHT * 2);
	data->y2 = ((data->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	data->zoom *= pow(1.001, 70);
	data->movex -= data->x2;
	data->movey -= data->y2;
}

void	zoomout(int x, int y, t_dataset *data)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	data->x2 = ((data->x - x) - WIDTH) / ((double)HEIGHT * 2);
	data->y2 = ((data->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	data->zoom /= pow(1.001, 70);
	data->movex -= data->x2;
	data->movey -= data->y2;
}

int		motion(int x, int y, t_dataset *data)
{
	
	ft_putendl("HERE4");//
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putnbr(y);


	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		ft_putendl("HERE5");//

		if ((data->fractol == 1 || data->fractol == 6) && data->movemouse == 1)
		{
			ft_putendl("HERE2");//

			data->clickx = x;
			data->clicky = y;
			data->cre = ((data->clickx - data->x) - WIDTH) / (((double)HEIGHT * 2) + data->y);
			data->cim = ((data->clicky + data->y) - HEIGHT) / ((double)HEIGHT * 2);
			render_scene(data);
			ft_putendl("HERE3");//

		}
	}
	return (0);
}
