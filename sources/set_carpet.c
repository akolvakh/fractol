//norm done
//review formulas

#include "fractol.h"

int		isfilled(t_dataset *data, int x, int y)//
{
	while (x > 0 || y > 0)
	{
		if (data->iteration < 5)
			data->iteration = 5;
		if (x % (int)data->iteration == 1 && y % (int)data->iteration == 1)//
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void	calculation_carpet(t_dataset *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (isfilled(data, x, y) == 1)
				render_image(0xFF0000, x, y, data);
			else
				render_image(0, x, y, data);
		}
	}
}
