#include "../../header/cub3D.h"

double  claim_decimal(double n)
{
    double result;

    modf(n, &result);
    return (result);
}