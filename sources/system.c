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
		data->fractol = 1;
	if (ft_strcmp(str, "mandel") == 0)
		data->fractol = 2;
	if (ft_strcmp(str, "ship") == 0)
		data->fractol = 3;
	if (ft_strcmp(str, "carpet") == 0)
		data->fractol = 4;
	if (ft_strcmp(str, "tricorn") == 0)
		data->fractol = 5;
	if (ft_strcmp(str, "juliacubed") == 0)
		data->fractol = 6;
	if (ft_strcmp(str, "mandelcubed") == 0)
		data->fractol = 7;
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
	|| (error == USAGE && (msg = "Fractols:\n1. julia\n2. mandel\n\
				3. ship\n4. carpet\n5. tricorn\n6. juliacubed \n7. mandelcubed\n\
				Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n\
				Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n\
				Zoom Reset: Space Bar\nJulia Activate: Right Click\n\
				Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5")))
		ft_putstr(msg);
	exit(-1);
}

void	sys_message(int message)
{
	char *msg;

	if ((message == USAGE && (msg = "Fractols:\n1. julia\n2. mandel\n\
				3. ship\n4. carpet\n5. tricorn\n6. juliacubed \n7. mandelcubed\n\
				Controls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\n\
				Mouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\n\
				Zoom Reset: Space Bar\nJulia Activate: Right Click\n\
				Color Change: Num Key 1-3\nHue Change: Num Key 4 & 5"))
	|| (message == START && (msg = "MESSAGE: Start the game\n"))
	|| (message == LEFT && (msg = "MESSAGE: Left\n"))
	|| (message == RIGHT && (msg = "MESSAGE: Right\n"))
	|| (message == UP && (msg = "MESSAGE: Up\n"))
	|| (message == DOWN && (msg = "MESSAGE: Down\n")))
		ft_putstr(msg);
}

void	sys_option(t_dataset *data)
{
	if (data->fractol == 1)
		juliafx(data);
	if (data->fractol == 2)
		mandelfx(data);
	if (data->fractol == 3)
		shipfx(data);
	if (data->fractol == 4)
		carpetfx(data);
	if (data->fractol == 5)
		tricornfx(data);
	if (data->fractol == 6)
		juliacubedfx(data);
	if (data->fractol == 7)
		mandelcubedfx(data);
}
