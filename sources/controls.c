#include "fractol.h"

int		mousehook(int mousekey, int x, int y, t_a *exp)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (mousekey == 5)
			zoomin(x, y, exp);
		else if (mousekey == 4)
			zoomout(x, y, exp);
		else if (mousekey == 1)
			exp->maxinter += 5;
		else if (mousekey == 2)
		{
			if (exp->movemouse == 1)
				exp->movemouse = 0;
			else
				exp->movemouse = 1;
		}
		rendering(exp);
	}
	return (0);
}

int		keyhooks3(int key, t_a *exp)
{
	if (key == 49)
		rendering(exp);
	if (key == 18)
	{
		exp->color = 1;
		rendering(exp);
	}
	else if (key == 126)
		exp->movey += .2 / exp->zoom;
	else if (key == 125)
		exp->movey -= .2 / exp->zoom;
	else if (key == 124)
		exp->movex += .2 / exp->zoom;
	else if (key == 123)
		exp->movex -= .2 / exp->zoom;
	return (0);
}

int		keyhooks2(int key, t_a *exp)
{
	if (key == 19)
	{
		exp->color = 0x247812;
		rendering(exp);
	}
	if (key == 20)
	{
		exp->color = 2000;
		rendering(exp);
	}
	if (key == 21)
	{
		exp->color += 50;
		rendering(exp);
	}
	if (key == 23)
	{
		exp->color -= 10;
		rendering(exp);
	}
	return (0);
}

int		keyhooks(int key, t_a *exp)
{
	if (!(exp->win))
		return (0);
	if (key == 53)
		sys_error(FINISH);
	else if (key == 116)
		exp->zoom *= pow(1.001, 70);
	else if (key == 121)
		exp->zoom /= pow(1.001, 70);
	else if (key == 24)
		exp->maxinter += 5;
	else if (key == 27)
		exp->maxinter -= 5;
	keyhooks2(key, exp);
	keyhooks3(key, exp);
	rendering(exp);
	return (0);
}
