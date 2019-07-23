//norm done
//review formulas

#include "fractol.h"

void			mandelassign(t_dataset *data)
{
	data->oldim = 0;
	data->oldre = data->oldim;
	data->newim = data->oldre;
	data->newre = data->newim;
}

static void		mandelmagic(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre - data->oldim * data->oldim + data->pr;
	data->newim = 2 * data->oldre * data->oldim + data->pi;
}

void			calculation_mandel(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->pr = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->pi = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			mandelassign(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				mandelmagic(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
				render_image(render_color(data->x, data->y, (data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}

static void		mandelfun(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = (data->oldre * data->oldre * data->oldre) -
		(data->oldim * data->oldre * data->oldim) -
			(2 * data->oldre * data->oldim * data->oldim) + data->pr;
	data->newim = (2 * data->oldre * data->oldre * data->oldim) -
			(data->oldim * data->oldim * data->oldim) + data->pi;
}

void			calculation_mandelcubed(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->pr = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->pi = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			mandelassign(data);
			data->i = -1;
			while (++data->i < data->iteration)
			{
				mandelfun(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
				render_image(render_color(data->x, data->y, (data->i * data->color), data), data->x, data->y, data);
			else
				render_image(200, data->x, data->y, data);
		}
	}
}
