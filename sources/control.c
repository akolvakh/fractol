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

int		controls_arrows(int key, t_dataset *ai)
{
	if (key == UP_ARROW)
		ai->moveY = ai->moveY - .2 / ai->zoom;
	else if (key == DOWN_ARROW)
		ai->moveY = ai->moveY + .2 / ai->zoom;
	else if (key == RIGHT_ARROW)
		ai->moveX = ai->moveX + .2 / ai->zoom;
	else if (key == LEFT_ARROW)
		ai->moveX = ai->moveY - .2 / ai->zoom;
	return (0);
}

int		controls_buttons(int key, t_dataset *ai)
{
	if (key == ESC)
		sys_error(FINISH);
	else if (key == PAGE_UP)
		ai->zoom = ai->zoom / pow(1.001, 70);
	else if (key == PAGE_DOWN)
		ai->zoom = ai->zoom * pow(1.001, 70);
	else if (key == PLUS)
		ai->itr = ai->itr + 5;
	else if (key == MINUS)
		ai->itr = ai->itr - 5;
	else if (key == SPACE)
		init_main(ai);
	return (0);
}

int		controls_numbers(int key, t_dataset *ai)
{
	if (key == ONE)
		ai->fractol = JULIA;
	else if (key == TWO)
		ai->fractol = MANDEL;
	else if (key == THREE)
		ai->fractol = SHIP;
	else if (key == FOUR)
		ai->fractol = TRICORN;
	else if (key == FIVE)
		ai->fractol = MANDELCUBED;
	else if (key == SIX)
		ai->color = 1;
	else if (key == SEVEN)
		ai->color = 10;
	else if (key == EIGTH)
		ai->color = 100;
	else if (key == TAB)
		ai->color = ai->color + 0.15;
	else if (key == SHIFT)
		ai->color = ai->color - 0.15;
	return (0);
}

int		controls_keys(int key, t_dataset *ai)
{
	if (!(ai->win))
		return (0);
	controls_numbers(key, ai);
	controls_arrows(key, ai);
	controls_buttons(key, ai);
	render_scene(ai);
	return (0);
}

int		controls_mouse(int mousekey, int x, int y, t_dataset *ai)
{
	if (x < WDT && y < HGT && x > 0 && y > 0)
	{
		if (mousekey == SCROLL_DOWN)
			formula_scale(1, x, y, ai);
		else if (mousekey == SCROLL_UP)
			formula_scale(0, x, y, ai);
		else if (mousekey == LEFT_CLICK)
			ai->itr += 3;
		else if (mousekey == RIGHT_CLICK)
			ai->movemouse = (ai->movemouse == 1) ? 0 : 1;
		render_scene(ai);
	}
	return (0);
}
