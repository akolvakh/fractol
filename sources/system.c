#include "fractol.h"

int		sys_close(t_a *exp)
{
	mlx_destroy_window(exp->mlx, exp->win);
	sys_error(FINISH);
	return (0);
}

void	sys_validator(char *str, t_a *exp)
{
	if ((!(ft_strcmp(str, "mandel") == 0)) && (!(ft_strcmp(str, "julia") == 0))
			&& (!(ft_strcmp(str, "ship") == 0)) && (!(ft_strcmp(str, "carpet")
					== 0)) && (!(ft_strcmp(str, "tricorn") == 0))
			&& (!(ft_strcmp(str, "juliacubed") == 0)) &&
			(!(ft_strcmp(str, "mandelcubed") == 0)))
		sys_error(VALUE);
	if (ft_strcmp(str, "julia") == 0)
		exp->fractol = 1;
	if (ft_strcmp(str, "mandel") == 0)
		exp->fractol = 2;
	if (ft_strcmp(str, "ship") == 0)
		exp->fractol = 3;
	if (ft_strcmp(str, "carpet") == 0)
		exp->fractol = 4;
	if (ft_strcmp(str, "tricorn") == 0)
		exp->fractol = 5;
	if (ft_strcmp(str, "juliacubed") == 0)
		exp->fractol = 6;
	if (ft_strcmp(str, "mandelcubed") == 0)
		exp->fractol = 7;
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
	|| (error == FINISH && (msg = "MESSAGE: Exit the program\n")))
		ft_putstr(msg);
	exit(-1);
}

void	sys_message(int message)
{
	char *msg;

	if ((message == USAGE && (msg = "Fractols:\n1. julia\n2. mandel\n3. ship\n4. carpet\n5. tricorn\n6. juliacubed \n7. mandelcubed\nControls:\nMove: Arrow Keys\nZoom: Page Up & Page Down\nMouse Zoom: Scrool Wheel\nIteration: Left Click & (+ -) Keys\nZoom Reset: Space Bar\nJulia Activate: Right Click\nColor Change: Num Key 1-3\nHue Change: Num Key 4 & 5"))
	|| (message == START && (msg = "MESSAGE: Start the game\n"))
	|| (message == LEFT && (msg = "MESSAGE: Left\n"))
	|| (message == RIGHT && (msg = "MESSAGE: Right\n"))
	|| (message == UP && (msg = "MESSAGE: Up\n"))
	|| (message == DOWN && (msg = "MESSAGE: Down\n")))
		ft_putstr(msg);
}

void	sys_option(t_a *exp)
{
	if (exp->fractol == 1)
		juliafx(exp);
	if (exp->fractol == 2)
		mandelfx(exp);
	if (exp->fractol == 3)
		shipfx(exp);
	if (exp->fractol == 4)
		carpetfx(exp);
	if (exp->fractol == 5)
		tricornfx(exp);
	if (exp->fractol == 6)
		juliacubedfx(exp);
	if (exp->fractol == 7)
		mandelcubedfx(exp);
}