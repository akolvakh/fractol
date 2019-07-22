#include "fractol.h"

static void		tricornmagic(t_a *exp)
{
	exp->oldre = exp->newre;
	exp->oldim = exp->newim * -1;
	exp->newre = exp->oldre * exp->oldre - exp->oldim * exp->oldim + exp->pr;
	exp->newim = 2 * exp->oldre * exp->oldim + exp->pi;
}

void			tricornfx(t_a *exp)
{
	exp->y = -1;
	while (++exp->y < HEIGHT)
	{
		exp->x = -1;
		while (++exp->x < WIDTH)
		{
			exp->pr = 1.5 * (exp->x - WIDTH / 2) /
				(0.5 * exp->zoom * WIDTH) + exp->movex;
			exp->pi = (exp->y - HEIGHT / 2) /
				(0.5 * exp->zoom * HEIGHT) + exp->movey;
			mandelassign(exp);
			exp->i = -1;
			while (++exp->i < exp->maxinter)
			{
				tricornmagic(exp);
				if ((exp->newre * exp->newre + exp->newim * exp->newim) > 4)
					break ;
			}
			if (exp->i < exp->maxinter)
				putimage(exp, exp->x, exp->y, (colormagic((exp->color *
					exp->i), exp->x, exp->y)));
			else
				putimage(exp, exp->x, exp->y, 200);
		}
	}
}
