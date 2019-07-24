/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:16 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:17 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		controls_arrows(int key, t_dataset *data)
{
	if (key == UP_ARROW)
		data->m_y -= .2 / data->zoom;
	else if (key == DOWN_ARROW)
		data->m_y += .2 / data->zoom;
	else if (key == RIGHT_ARROW)
		data->m_x += .2 / data->zoom;
	else if (key == LEFT_ARROW)
		data->m_x -= .2 / data->zoom;
	return (0);
}

int		controls_buttons(int key, t_dataset *data)
{
	if (key == ESC)
		sys_error(FINISH);
	else if (key == PAGE_UP)
		data->zoom /= pow(1.001, 70);
	else if (key == PAGE_DOWN)
		data->zoom *= pow(1.001, 70);
	else if (key == PLUS)
		data->itr += 5;
	else if (key == MINUS)
		data->itr -= 5;
	else if (key == SPACE)
		init_main(data);
	return (0);
}

int		controls_numbers(int key, t_dataset *data)
{
	if (key == ONE)
		data->fractol = JULIA;
	else if (key == TWO)
		data->fractol = MANDEL;
	else if (key == THREE)
		data->fractol = SHIP;
	else if (key == FOUR) // change menu
		data->fractol = TRICORN;
	else if (key == FIVE)
		data->fractol = MANDELCUBED;
	else if (key == SIX)
		data->color = 1;
	else if (key == SEVEN)
		data->color = GREEN;
	else if (key == EIGTH)
		data->color = 1000;
	else if (key == TAB)
		data->color += 35;
	else if (key == SHIFT)
		data->color -= 15;
	return (0);
}

int		controls_keys(int key, t_dataset *data)
{
	if (!(data->win))
		return (0);
	controls_numbers(key, data);
	controls_arrows(key, data);
	controls_buttons(key, data);
	render_scene(data);
	return (0);
}

int		controls_mouse(int mousekey, int x, int y, t_dataset *data)
{
	if (x < WDT && y < HGT && x > 0 && y > 0)
	{
		if (mousekey == SCROLL_DOWN)
			scale(1, x, y, data);
		else if (mousekey == SCROLL_UP)
			scale(0, x, y, data);
		else if (mousekey == LEFT_CLICK)
			data->itr += 3;
		else if (mousekey == RIGHT_CLICK)
		{
			if (data->movemouse == 1)
				data->movemouse = 0;
			else
				data->movemouse = 1;
		}
		render_scene(data);
	}
	return (0);
}
