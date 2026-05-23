#include "../../header/cub3D.h"

double  claim_decimal(double n)
{
    double integer;
    double dec;

    dec = modf(n, &integer);
    return (dec);
}