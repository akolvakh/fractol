#include "fractol.h"

static void		juliamagic(t_a *exp)
{
	exp->oldre = exp->newre;
	exp->oldim = exp->newim;
	exp->newre = exp->oldre * exp->oldre - exp->oldim * exp->oldim + exp->cre;
	exp->newim = 2 * exp->oldre * exp->oldim + exp->cim;
}

void			juliafx(t_a *exp)
{
	exp->y = -1;
	while (++exp->y < HEIGHT)
	{
		exp->x = -1;
		while (++exp->x < WIDTH)
		{
			exp->newre = 1.5 * (exp->x - WIDTH / 2) /
				(0.5 * exp->zoom * WIDTH) + exp->movex;
			exp->newim = (exp->y - HEIGHT / 2) /
				(0.5 * exp->zoom * HEIGHT) + exp->movey;
			exp->i = -1;
			while (++exp->i < exp->maxinter)
			{
				juliamagic(exp);
				if ((exp->newre * exp->newre + exp->newim) > 4)
					break ;
			}
			if (exp->i < exp->maxinter)
				putimage(exp, exp->x, exp->y, (colormagic((exp->i *
					exp->color), exp->x, exp->y)));
			else
				putimage(exp, exp->x, exp->y, 0x000000);
		}
	}
}

static void		juliacubedfun(t_a *exp)
{
	exp->oldre = exp->newre;
	exp->oldim = exp->newim;
	exp->newre = (exp->oldre * exp->oldre * exp->oldre) -
		(exp->oldim * exp->oldim * exp->oldre) -
		(2 * exp->oldre * exp->oldim * exp->oldim) + exp->cre;
	exp->newim = (3 * exp->oldre * exp->oldre * exp->oldim) -
		(exp->oldim * exp->oldim * exp->oldim) + exp->cim;
}

void			juliacubedfx(t_a *exp)
{
	exp->y = -1;
	while (++exp->y < HEIGHT)
	{
		exp->x = -1;
		while (++exp->x < WIDTH)
		{
			exp->newre = 1.5 * (exp->x - WIDTH / 2) /
				(0.5 * exp->zoom * WIDTH) + exp->movex;
			exp->newim = (exp->y - HEIGHT / 2) /
				(0.5 * exp->zoom * HEIGHT) + exp->movey;
			exp->i = -1;
			while (++exp->i < exp->maxinter)
			{
				juliacubedfun(exp);
				if ((exp->newre * exp->newre + exp->newim) > 4)
					break ;
			}
			if (exp->i < exp->maxinter)
				putimage(exp, exp->x, exp->y, (colormagic((exp->i *
					exp->color), exp->x, exp->y)));
			else
				putimage(exp, exp->x, exp->y, 0x000000);
		}
	}
}
