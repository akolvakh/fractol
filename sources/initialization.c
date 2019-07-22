#include "fractol.h"

void	init_julia(t_a *exp)
{
	exp->zoom = 1;
	exp->movex = 0;
	exp->movey = 0;
	exp->maxinter = 15;
	exp->cre = -0.7;
	exp->cim = 0.27015;
}

void	init_mandel(t_a *exp)
{
	exp->zoom = 1;
	exp->movex = 0;
	exp->movey = 0;
	exp->maxinter = 15;
}

void	init_ship(t_a *exp)
{
	exp->zoom = 1;
	exp->movex = 0;
	exp->movey = 0;
	exp->maxinter = 15;
}

void	init_carpet(t_a *exp)
{
	exp->zoom = 1;
	exp->movex = 0;
	exp->movey = 0;
	exp->maxinter = 3;
}

void	init_main(t_a *exp)
{
	if (exp->fractol == 1)
		init_julia(exp);
	if (exp->fractol == 2)
		init_mandel(exp);
	if (exp->fractol == 3)
		init_ship(exp);
	if (exp->fractol == 4)
		init_carpet(exp);
	if (exp->fractol == 5)
		init_mandel(exp);
	if (exp->fractol == 6)
		init_julia(exp);
	if (exp->fractol == 7)
		init_mandel(exp);
}
