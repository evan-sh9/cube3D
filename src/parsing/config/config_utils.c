#include "../../../header/cub3D.h"

void	n_setting_check(t_pars *pars)
{
	if (pars->find_t_var.NO > 1)
		invalid_map();
	if (pars->find_t_var.SO > 1)
		invalid_map();
	if (pars->find_t_var.WE > 1)
		invalid_map();
	if (pars->find_t_var.EA > 1)
		invalid_map();
}

void	n_setting_is_find(t_pars *pars)
{
	if (pars->find_t_var.NO < 1)
		invalid_map();
	if (pars->find_t_var.SO < 1)
		invalid_map();
	if (pars->find_t_var.WE < 1)
		invalid_map();
	if (pars->find_t_var.EA < 1)
		invalid_map();
}
