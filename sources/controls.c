/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:25:49 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:25:51 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		controls_arrows(int key, t_dataset *data)
{
	if (key == UP_ARROW)
		data->movey -= .2 / data->zoom;
	else if (key == DOWN_ARROW)
		data->movey += .2 / data->zoom;
	else if (key == RIGHT_ARROW)
		data->movex += .2 / data->zoom;
	else if (key == LEFT_ARROW)
		data->movex -= .2 / data->zoom;
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
		data->iteration += 5;
	else if (key == MINUS)
		data->iteration -= 5;
	else if (key == SPACE)
		init_main(data);
	return (0);
}

int		controls_numbers(int key, t_dataset *data)
{
	if (key == ONE)
		data->color = 1;
	else if (key == TWO)
		data->color = GREEN;
	else if (key == THREE)
		data->color = 1000;
	else if (key == FOUR)
		data->color += 35;
	else if (key == FIVE)
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
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		if (mousekey == SCROLL_DOWN)
			zoomin(x, y, data);
		else if (mousekey == SCROLL_UP)
			zoomout(x, y, data);
		else if (mousekey == LEFT_CLICK)
			data->iteration += 5;
		else if (mousekey == RIGHT_CLICK)
		{
			ft_putendl("HERE1");//
			if (data->movemouse == 1)
				data->movemouse = 0;
			else
				data->movemouse = 1;
		}
		render_scene(data);
			ft_putendl("HERE4");//
			ft_putnbr(x);
			ft_putchar('\n');
			ft_putnbr(y);
	}
	return (0);
}
