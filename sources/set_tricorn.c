#include "fractol.h"

static void		tricornmagic(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim * -1;
	data->newre = data->oldre * data->oldre - data->oldim * data->oldim + data->pr;
	data->newim = 2 * data->oldre * data->oldim + data->pi;
}

void			tricornfx(t_dataset *data)
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
			while (++data->i < data->maxinter)
			{
				tricornmagic(data);
				if ((data->newre * data->newre + data->newim * data->newim) > 4)
					break ;
			}
			if (data->i < data->maxinter)
				putimage(data, data->x, data->y, (colormagic(data, (data->color *
					data->i), data->x, data->y)));
			else
				putimage(data, data->x, data->y, 200);
		}
	}
}
