#include "fractol.h"

int				isfilled(int x, int y, t_a *exp)
{
	while (x > 0 || y > 0)
	{
		if (exp->maxinter < 5)
			exp->maxinter = 5;
		if (x % (int)exp->maxinter == 1 && y % (int)exp->maxinter == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void			carpetfx(t_a *exp)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (isfilled(x, y, exp) == 1)
				putimage(exp, x, y, 0xFF0000);
			else
				putimage(exp, x, y, 0);
		}
	}
}
