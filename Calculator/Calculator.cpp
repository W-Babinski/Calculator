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
                << "\n\tTo modify your result\n" 
                << "\tcontinue with <operator> number.\n" 
                << "\tType c1 to reset\n\n";

    Calc_func c;
    while (true) {                                                          //main calculator loop
        std::cin >> x >> oper >> y;                                                 
        if (std::cin.fail()) {                                              //checking if the numerical input is correct, if not will prompt user to repeat
            cleanUp();                                                      //cleanUp() clearing cin stream to correctly reset
            continue;
        }

        if (exceptionHandle(oper, y)) {                                     //"x/0" check alongside proper operator use
            continue;
        }

        result = c.Calculate(x, oper, y);
        std::cout << "Result is: " << result;

        while (true) {                                                      //secondary calculator loop used for further operations on result variable
            std::cin >> oper2 >> y;                                                 
           
            if (std::cin.fail()) {                                          //input check
                cleanUp();
                std::cout << "Result is: " << result;
                continue;
            }

            if (oper2 == 'c') {                                             //reset check
                std::cout << "____________________\n";
                break;
            }
            
            oper = oper2;

            if (exceptionHandle(oper, y)) {                                 //checking for x/0 and doing a check for correct operator
                std::cout << "Result is: " << result;
                continue;
            }
                 
            result = c.Calculate(result, oper, y);
            std::cout << "Result is: " << result;
                
        }
    }
}