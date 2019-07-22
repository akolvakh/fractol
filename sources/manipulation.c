#include "fractol.h"

void	zoomin(int x, int y, t_a *exp)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	exp->x2 = ((exp->x - x) - WIDTH) / ((double)HEIGHT * 2);
	exp->y2 = ((exp->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	exp->zoom *= pow(1.001, 70);
	exp->movex -= exp->x2;
	exp->movey -= exp->y2;
}

void	zoomout(int x, int y, t_a *exp)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	exp->x2 = ((exp->x - x) - WIDTH) / ((double)HEIGHT * 2);
	exp->y2 = ((exp->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	exp->zoom /= pow(1.001, 70);
	exp->movex -= exp->x2;
	exp->movey -= exp->y2;
}

int		motion(int x, int y, t_a *exp)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if ((exp->fractol == 1 || exp->fractol == 6) && exp->movemouse == 1)
		{
			exp->clickx = x;
			exp->clicky = y;
			exp->cre = ((exp->clickx - exp->x) - WIDTH) /
				(((double)HEIGHT * 2) + exp->y);
			exp->cim = ((exp->clicky + exp->y) - HEIGHT) /
				((double)HEIGHT * 2);
			rendering(exp);	
		}
	}
	return (0);
}
