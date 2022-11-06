#include <iostream>
#include "Calc_func.h"

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';
    char oper2 = '+';
    bool open = true;

    std::cout << "A simple calculator console app" <<"\t\t|\tSupported formats :\n" 
                << "Please enter an operation. " << "\t\t|\ta + b | a - b | a * b | a / b| a ^ b\n"
                << "\n\tTo modify your result\n\tcontinue with <operator> number.\n\tType c1 to reset\n\n";

    Calc_func c;
    while (true) {                                                                          //main calculator loop
        std::cin >> x >> oper2 >> y;                                                        //checking if the numerical input is correct, if not will prompt user to repeat
        if (std::cin.fail()) {                                                              //TODO: operator check
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Wrong input, try again\n";
            continue;
        }
        if (oper2 != 'c') {
            oper = oper2;
            if (oper == '/' && y == 0) {
                std::cout << "Division by zero. Try again.\n" << "Result is: " << result;
                continue;
            }
            result = c.Calculate(x, oper, y);
            std::cout << "Result is: " << result;
        }
        else {
            std::cout << "____________________\n";
            break;
        }
        
        while (true) {                                                                      //secondary calculator loop used for further operations on result variable
            std::cin >> oper2 >> y;                                                         //no real difference from the first one aside from changing 'x' input to result
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Wrong input, try again\n";
                continue;
            }
            if (oper2 != 'c') {
                oper = oper2;
                if (oper == '/' && y == 0) {
                    std::cout << "Division by zero. Try again.\n" << "Result is: " << result;
                    continue;
                }
                result = c.Calculate(result, oper, y);
                std::cout << "Result is: " << result;
            }
            else {
                std::cout << "____________________\n";
                break;
            }
        }
    }
}