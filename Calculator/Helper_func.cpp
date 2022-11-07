#include "Helper_func.h"
#include <iostream>

void cinStreamClear() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

bool isOperationCorrect(char oper, double y) {
	return (oper == '/' && y != 0) || (oper == '+' || oper == '-' || oper == '*' || oper == '^');
}