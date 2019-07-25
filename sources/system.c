/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:50 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:51 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		sys_close(t_dataset *ai)
{
	mlx_destroy_window(ai->mlx, ai->win);
	free(ai);//
	sys_error(FINISH);
	return (0);
}

void	sys_error(int err)
{
	char *out;

	if ((err == MAP && (out = "ERROR: invalid map\n"))
	|| (err == MLX && (out = "ERROR: can't initialize mlx\n"))
	|| (err == IMG && (out = "ERROR: can't create image mlx\n"))
	|| (err == WIN && (out = "ERROR: can't create window\n"))
	|| (err == VALUE && (out = "ERROR: invalid value\n"))
	|| (err == IMG_PTR && (out = "ERROR: can't get image ptr\n"))
	|| (err == FILE && (out = "ERROR: can't open file\n"))
	|| (err == MALLOC && (out = "ERROR: can't malloc memory\n"))
	|| (err == INPUT && (out = "ERROR: too much input\n"))
	|| (err == FINISH && (out = "MESSAGE: Exit the program\n"))
	|| (err == TEXTURE && (out = "ERROR: invalid textures\n"))
	|| (err == USAGE && (out = "ERROR: invalid input. Read it ->\n\n"
				"Fractols:\n1. julia\n2. mandel\n3. ship\n"
				"4. tricorn\n5. mandelcubed\n"
				"Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n"
				"Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n"
				"Zoom Reset: Space Bar\nJulia Activate: Right Click\n"
				"Color Change: Num Key 6-8\nHue Change: Tab & Shift\n")))
		ft_putstr(out);
	exit(-1);
}

void	sys_message(int msg)
{
	char *out;

	if ((msg == USAGE && (out = "Fractols:\n1. julia\n2. mandel\n3. ship\n"
				"4. tricorn\n5. mandelcubed\n"
				"Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n"
				"Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n"
				"Zoom Reset: Space Bar\nJulia Activate: Right Click\n"
				"Color Change: Num Key 6-8\nHue Change: Tab & Shift\n"))
	|| (msg == START && (out = "MESSAGE: Start the game\n"))
	|| (msg == LEFT && (out = "MESSAGE: Left\n"))
	|| (msg == RIGHT && (out = "MESSAGE: Right\n"))
	|| (msg == UP && (out = "MESSAGE: Up\n"))
	|| (msg == DOWN && (out = "MESSAGE: Down\n")))
		ft_putstr(out);
}

void	sys_option(t_dataset *ai)
{
	if (ai->fractol == MANDELCUBED)
		algo_general(MANDELCUBED, ai);
	if (ai->fractol == TRICORN)
		algo_general(TRICORN, ai);
	if (ai->fractol == SHIP)
		algo_general(SHIP, ai);
	if (ai->fractol == MANDEL)
		algo_general(MANDEL, ai);
	if (ai->fractol == JULIA)
		algo_julia(ai);
}

void	sys_validator(t_dataset *ai, char *input)
{
	if (ft_strcmp(input, "julia") == 0)
		ai->fractol = JULIA;
	else if (ft_strcmp(input, "mandel") == 0)
		ai->fractol = MANDEL;
	else if (ft_strcmp(input, "ship") == 0)
		ai->fractol = SHIP;
	else if (ft_strcmp(input, "tricorn") == 0)
		ai->fractol = TRICORN;
	else if (ft_strcmp(input, "mandelcubed") == 0)
		ai->fractol = MANDELCUBED;
	else if ((!(ft_strcmp(input, "tricorn") == 0))
		&& (!(ft_strcmp(input, "ship") == 0))
		&& (!(ft_strcmp(input, "julia") == 0))
		&& (!(ft_strcmp(input, "mandel") == 0))
		&& (!(ft_strcmp(input, "mandelcubed") == 0)))
		sys_error(USAGE);
	ft_putendl(input);
}
