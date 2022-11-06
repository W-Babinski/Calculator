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

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
