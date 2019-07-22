#include "fractol.h"

void			putimage(t_dataset *data, int x, int y, int color)
{
	int	i;

	i = (x * (data->bpp / 8)) + (y * data->s1);
	data->imgpointer[i] = color;
	data->imgpointer[++i] = color >> 8;
	data->imgpointer[++i] = color >> 16;
}

unsigned int	colormagic(t_dataset *data,int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	data->chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	data->chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	data->chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (data->chan[0] << 16) + (data->chan[1] << 8) + (data->chan[2] + 255);
	return (color);
}
