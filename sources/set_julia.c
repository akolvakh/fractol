//norm done
//review formulas

#include "fractol.h"

static void		juliamagic(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre - data->oldim * data->oldim + data->cre;
	data->newim = 2 * data->oldre * data->oldim + data->cim;
}

void			calculation_julia(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->newre = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->newim = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			data->i = -1;
			while (++data->i < data->iteration)
			{
				juliamagic(data);
				if ((data->newre * data->newre + data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
				render_image(data, data->x, data->y, (render_color(data, (data->i *
					data->color), data->x, data->y)));
			else
				render_image(data, data->x, data->y, 0x000000);
		}
	}
}

static void		juliacubedfun(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = (data->oldre * data->oldre * data->oldre) -
		(data->oldim * data->oldim * data->oldre) -
		(2 * data->oldre * data->oldim * data->oldim) + data->cre;
	data->newim = (3 * data->oldre * data->oldre * data->oldim) -
		(data->oldim * data->oldim * data->oldim) + data->cim;
}

void			calculation_juliacubed(t_dataset *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->newre = 1.5 * (data->x - WIDTH / 2) /
				(0.5 * data->zoom * WIDTH) + data->movex;
			data->newim = (data->y - HEIGHT / 2) /
				(0.5 * data->zoom * HEIGHT) + data->movey;
			data->i = -1;
			while (++data->i < data->iteration)
			{
				juliacubedfun(data);
				if ((data->newre * data->newre + data->newim) > 4)
					break ;
			}
			if (data->i < data->iteration)
				render_image(data, data->x, data->y, (render_color(data, (data->i *
					data->color), data->x, data->y)));
			else
				render_image(data, data->x, data->y, 0x000000);
		}
	}
}
