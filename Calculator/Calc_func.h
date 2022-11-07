#pragma once
class Calc_func
{
public:
	double Calculate(double x, char oper, double y);
};

void cleanUp();

bool exceptionHandle(char oper, double y);
