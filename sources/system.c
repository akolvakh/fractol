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

int		sys_close(t_dataset *data)
{
	mlx_destroy_window(data->mlx, data->win);
	sys_error(FINISH);
	return (0);
}

void	sys_error(int err)
{
	char *out;

	if ((err == MAP && (out = "ERROR: invalid map\n"))
	|| (err == MLX && (out = "ERROR: can't initialize mlx\n"))
	|| (err == WIN && (out = "ERROR: can't create window\n"))
	|| (err == VALUE && (out = "ERROR: invalid value\n"))
	|| (err == FILE && (out = "ERROR: can't open file\n"))
	|| (err == MALLOC && (out = "ERROR: can't malloc memory\n"))
	|| (err == INPUT && (out = "ERROR: too much input\n"))
	|| (err == FINISH && (out = "MESSAGE: Exit the program\n"))
	|| (err == USAGE && (out = "Fractols:\n1. julia\n2. mandel\n3. ship\n"
				"4. tricorn\n5. mandelcubed\n"
				"Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n"
				"Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n"
				"Zoom Reset: Space Bar\nJulia Activate: Right Click\n"
				"Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5")))
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
				"Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5"))
	|| (msg == START && (out = "MESSAGE: Start the game\n"))
	|| (msg == LEFT && (out = "MESSAGE: Left\n"))
	|| (msg == RIGHT && (out = "MESSAGE: Right\n"))
	|| (msg == UP && (out = "MESSAGE: Up\n"))
	|| (msg == DOWN && (out = "MESSAGE: Down\n")))
		ft_putstr(out);
}

void	sys_option(t_dataset *data)
{
	if (data->fractol == MANDELCUBED)
		algo_mandelcubed(data);
	if (data->fractol == TRICORN)
		algo_tricorn(data);
	if (data->fractol == SHIP)
		algo_ship(data);
	if (data->fractol == MANDEL)
		algo_mandel(data);
	if (data->fractol == JULIA)
		algo_julia(data);
}

void	sys_validator(t_dataset *data, char *input)
{
	if ((!(ft_strcmp(input, "tricorn") == 0))
		&& (!(ft_strcmp(input, "ship") == 0))
		&& (!(ft_strcmp(input, "julia") == 0))
		&& (!(ft_strcmp(input, "mandel") == 0))
		&& (!(ft_strcmp(input, "mandelcubed") == 0)))
		sys_error(USAGE);
	ft_putendl(input);
	if (ft_strcmp(input, "julia") == 0)
		data->fractol = JULIA;
	if (ft_strcmp(input, "mandel") == 0)
		data->fractol = MANDEL;
	if (ft_strcmp(input, "ship") == 0)
		data->fractol = SHIP;
	if (ft_strcmp(input, "tricorn") == 0)
		data->fractol = TRICORN;
	if (ft_strcmp(input, "mandelcubed") == 0)
		data->fractol = MANDELCUBED;
}
