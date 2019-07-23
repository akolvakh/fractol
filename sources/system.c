//review this file
//norm done
//review sys_validator & sys_option

#include "fractol.h"

int		sys_close(t_dataset *data)
{
	mlx_destroy_window(data->mlx, data->win);
	sys_error(FINISH);
	return (0);
}

void	sys_validator(char *str, t_dataset *data)
{
	if ((!(ft_strcmp(str, "mandel") == 0)) && (!(ft_strcmp(str, "julia") == 0))
			&& (!(ft_strcmp(str, "ship") == 0)) && (!(ft_strcmp(str, "carpet")
					== 0)) && (!(ft_strcmp(str, "tricorn") == 0))
			&& (!(ft_strcmp(str, "juliacubed") == 0)) &&
			(!(ft_strcmp(str, "mandelcubed") == 0)))
		sys_error(USAGE);
	if (ft_strcmp(str, "julia") == 0)
		data->fractol = JULIA;
	if (ft_strcmp(str, "mandel") == 0)
		data->fractol = MANDEL;
	if (ft_strcmp(str, "ship") == 0)
		data->fractol = SHIP;
	if (ft_strcmp(str, "carpet") == 0)
		data->fractol = CARPET;
	if (ft_strcmp(str, "tricorn") == 0)
		data->fractol = TRICORN;
	if (ft_strcmp(str, "juliacubed") == 0)
		data->fractol = JULIACUBED;
	if (ft_strcmp(str, "mandelcubed") == 0)
		data->fractol = MANDELCUBED;
}

void	sys_error(int error)
{
	char *msg;

	if ((error == MAP && (msg = "ERROR: invalid map\n"))
	|| (error == MLX && (msg = "ERROR: can't initialize mlx\n"))
	|| (error == WIN && (msg = "ERROR: can't create window\n"))
	|| (error == VALUE && (msg = "ERROR: invalid value\n"))
	|| (error == FILE && (msg = "ERROR: can't open file\n"))
	|| (error == MALLOC && (msg = "ERROR: can't malloc memory\n"))
	|| (error == INPUT && (msg = "ERROR: too much input\n"))
	|| (error == FINISH && (msg = "MESSAGE: Exit the program\n"))
	|| (error == USAGE && (msg = "Fractols:\n1. julia\n2. mandel\n" 
				"3. ship\n4. carpet\n5. tricorn\n6. juliacubed \n7. mandelcubed\n"
				"Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n"
				"Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n"
				"Zoom Reset: Space Bar\nJulia Activate: Right Click\n"
				"Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5")))
		ft_putstr(msg);
	exit(-1);
}

void	sys_message(int message)
{
	char *msg;

	if ((message == USAGE && (msg = "Fractols:\n1. julia\n2. mandel\n" 
				"3. ship\n4. carpet\n5. tricorn\n6. juliacubed \n7. mandelcubed\n"
				"Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n"
				"Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n"
				"Zoom Reset: Space Bar\nJulia Activate: Right Click\n"
				"Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5"))
	|| (message == START && (msg = "MESSAGE: Start the game\n"))
	|| (message == LEFT && (msg = "MESSAGE: Left\n"))
	|| (message == RIGHT && (msg = "MESSAGE: Right\n"))
	|| (message == UP && (msg = "MESSAGE: Up\n"))
	|| (message == DOWN && (msg = "MESSAGE: Down\n")))
		ft_putstr(msg);
}

void	sys_option(t_dataset *data)
{
	if (data->fractol == MANDELCUBED)
		calculation_mandelcubed(data);
	if (data->fractol == JULIACUBED)
		calculation_juliacubed(data);
	if (data->fractol == TRICORN)
		calculation_tricorn(data);
	if (data->fractol == CARPET)
		calculation_carpet(data);
	if (data->fractol == SHIP)
		calculation_ship(data);
	if (data->fractol == MANDEL)
		calculation_mandel(data);
	if (data->fractol == JULIA)
		calculation_julia(data);
}
