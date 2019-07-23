#include "fractol.h"

void	init_julia(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
	data->cre = -0.7;
	data->cim = 0.27015;
}

void	init_mandel(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
}

void	init_ship(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 15;
	data->zoom = 0.5;
}

void	init_carpet(t_dataset *data)
{
	data->movex = 0;
	data->movey = 0;
	data->iteration = 3;
	data->zoom = 0.5;
}

void	init_main(t_dataset *data)
{
	if (data->fractol == 1)
		init_mandel(data);
	if (data->fractol == 2)
		init_julia(data);
	if (data->fractol == 3)
		init_mandel(data);
	if (data->fractol == 4)
		init_carpet(data);
	if (data->fractol == 5)
		init_ship(data);
	if (data->fractol == 6)
		init_mandel(data);
	if (data->fractol == 7)
		init_julia(data);
}
