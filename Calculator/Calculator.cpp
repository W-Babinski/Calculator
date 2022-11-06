#include <iostream>
#include "Calc_func.h"

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';    
    
    std::cout << "A simple calculator console app\n" << "Please enter an operation. Format:\n" << "a+b | a-b | a*b | a/b\n";

    Calc_func c;
    while (true) {
        std::cin >> x >> oper >> y;
        if (oper == '/' && y == 0) {
            std::cout << "Division by zero exception.\n";
            continue;
        }
        result = c.Calculate(x, oper, y);
        std::cout << "Result is : " << result << '\n';
    }
}