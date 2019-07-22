#include "fractol.h"

int		mousehook(int mousekey, int x, int y, t_dataset *data)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (mousekey == 5)
			zoomin(x, y, data);
		else if (mousekey == 4)
			zoomout(x, y, data);
		else if (mousekey == 1)
			data->maxinter += 5;
		else if (mousekey == 2)
		{
			if (data->movemouse == 1)
				data->movemouse = 0;
			else
				data->movemouse = 1;
		}
		rendering(data);
	}
	return (0);
}

int		keyhooks3(int key, t_dataset *data)
{
	if (key == 49)
		rendering(data);
	if (key == 18)
	{
		data->color = 1;
		rendering(data);
	}
	else if (key == 126)
		data->movey += .2 / data->zoom;
	else if (key == 125)
		data->movey -= .2 / data->zoom;
	else if (key == 124)
		data->movex += .2 / data->zoom;
	else if (key == 123)
		data->movex -= .2 / data->zoom;
	return (0);
}

int		keyhooks2(int key, t_dataset *data)
{
	if (key == 19)
	{
		data->color = 0x247812;
		rendering(data);
	}
	if (key == 20)
	{
		data->color = 2000;
		rendering(data);
	}
	if (key == 21)
	{
		data->color += 50;
		rendering(data);
	}
	if (key == 23)
	{
		data->color -= 10;
		rendering(data);
	}
	return (0);
}

int		keyhooks(int key, t_dataset *data)
{
	if (!(data->win))
		return (0);
	if (key == 53)
		sys_error(FINISH);
	else if (key == 116)
		data->zoom *= pow(1.001, 70);
	else if (key == 121)
		data->zoom /= pow(1.001, 70);
	else if (key == 24)
		data->maxinter += 5;
	else if (key == 27)
		data->maxinter -= 5;
	keyhooks2(key, data);
	keyhooks3(key, data);
	rendering(data);
	return (0);
}
