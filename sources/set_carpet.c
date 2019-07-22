#include "fractol.h"

int				isfilled(int x, int y, t_dataset *data)
{
	while (x > 0 || y > 0)
	{
		if (data->maxinter < 5)
			data->maxinter = 5;
		if (x % (int)data->maxinter == 1 && y % (int)data->maxinter == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void			carpetfx(t_dataset *data)
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
				putimage(data, x, y, 0xFF0000);
			else
				putimage(data, x, y, 0);
		}
	}
}
