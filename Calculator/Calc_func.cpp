#include "Calc_func.h"
#include <cmath>
#include <iostream>

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
void cleanUp() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Error. Wrong input, try again\n";
};

bool exceptionHandle(char oper, double y) {
	if (oper == '/' && y == 0) {
		std::cout << "Division by zero. Try again.\n";
		return true;
	}
	else if (!(oper == '+' 
				|| oper == '-' 
				|| oper == '*' 
				|| oper == '/' 
				|| oper == '^')) {
		std::cout << "Error. Unidentified operator. Try again.\n";
		return true;
	}
	else return false;
}
