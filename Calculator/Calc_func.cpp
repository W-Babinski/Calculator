#include "Calc_func.h"
#include <cmath>

double Calc_func::Calculate(double x, char oper, double y)
{
	switch (oper)
	{
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case '*':
		return x * y;
		break;
	case '/':
		return x / y;
		break;
	case '^':
		return pow(x, y);
		break;
	default:
		return 0.0;
	}
}
