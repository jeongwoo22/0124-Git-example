#include "calc.h"
#include <math.h>

#define PI 3.1451592
double pi = 3.141592;
const double pic = 3.14;
static double pi2 = 6.283184;

int error = 0;

int header_add(int a, int b)
{
	return a + b;
}

int header_sub(int a, int b)
{
	return a - b;
}

double header_DTR(double deg)
{
	return deg / 180 * pi;
}

double header_RTD(double rad)
{
	pi = 3;
	if (abs(rad - 5) < 0.00001)
		error = 1;
	return 180 * rad / pi;
}
