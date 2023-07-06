#include <iostream>
#include <string>
#include <sstream>

// Function to evaluate binary mathematical expressions
int evaluateExpression(const std::string& expression) {
    std::istringstream iss(expression);

    int operand1, operand2;
    char oper;
    if (iss >> operand1 >> oper >> operand2) {
        switch (oper) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw std::runtime_error("Error: Division by zero");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Syntax error");
        }
    }
    throw std::runtime_error("Syntax error");
}

int main() {
    std::string input;
    std::cout << "Enter desired mathematical expressions with operators '+' '-' '*' '/'. Enter 'Quit' to terminate input:\n";
    while (std::cout << "> " && std::getline(std::cin, input) && input != "Quit") {
        try {
            int result = evaluateExpression(input);
            std::cout << result << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}