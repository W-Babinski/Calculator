#include <iostream>
#include "Calc_func.h"
#include "Helper_func.h"

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';
    char oper2 = '+';

    std::cout << "A simple calculator console app" <<"\t\t|\tSupported formats :\n" 
                << "Please enter an operation. " << "\t\t|\ta + b | a - b | a * b | a / b| a ^ b\n"
                << "\n\tTo modify your result\n" 
                << "\tcontinue with <operator> number.\n" 
                << "\tType c1 to reset\n\n";

    Calc_func c;
    //main calculator loop
    while (true) {

        std::cin >> x >> oper >> y;

        //checking if the numerical input is correct, if not will prompt user to repeat
        if (std::cin.fail()) {
            cinStreamClear();
            std::cout << "Wrong input, try again\n";
            continue;
        }

        //checking for division by zero alongside proper operator use
        if (!(isOperationCorrect(oper, y))) {
            std::cout << "Error. Unidentified operator or division by zero. Try again.\n";
            continue;
        }
        //calculating the result and printing
        result = c.Calculate(x, oper, y);
        std::cout << "Result is: " << result;

        //secondary calculator loop used for further operations on result variable
        while (true) {    

            std::cin >> oper2 >> y;
            
            //input check
            if (std::cin.fail()) {
                cinStreamClear();
                std::cout << "Error. Wrong input, try again\n";
                std::cout << "Result is: " << result;
                continue;
            }

            //reset check
            if (oper2 == 'c') {
                std::cout << "____________________\n";
                break;
            }
            
            oper = oper2;

            //checking for x/0 and doing a check for correct operator
            if (!(isOperationCorrect(oper, y))) {
                std::cout << "Error. Unidentified operator or division by zero. Try again.\n";
                std::cout << "Result is: " << result;
                continue;
            }
            
            result = c.Calculate(result, oper, y);
            std::cout << "Result is: " << result;
        }
    }
}