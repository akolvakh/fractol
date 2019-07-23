#include "fractol.h"

int				isfilled(int x, int y, t_dataset *data)
{
	while (x > 0 || y > 0)
	{
		if (data->iteration < 5)
			data->iteration = 5;
		if (x % (int)data->iteration == 1 && y % (int)data->iteration == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void			calculation_carpet(t_dataset *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (isfilled(x, y, data) == 1)
				render_image(data, x, y, 0xFF0000);
			else
				render_image(data, x, y, 0);
		}
	}
}
