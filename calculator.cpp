#include <iostream>  // Include the standard input-output stream library

using namespace std;  // Use the standard namespace

// Function prototypes: Declare the functions that will be defined later
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;  // Variables to store the two numbers and the result
    char operation;  // Variable to store the operation selected by the user

    while (true) {  // Infinite loop to continuously prompt the user
        showMenu();  // Display the menu
        cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;  // Read the operation from the user

        if (operation == 'q' || operation == 'Q') {  // Check if the user wants to quit
            break;  // Exit the loop
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;  // Read the two numbers from the user

        // Perform the operation based on the user's input
        switch (operation) {
            case '+':
                result = add(num1, num2);  // Call the add function
                break;
            case '-':
                result = subtract(num1, num2);  // Call the subtract function
                break;
            case '*':
                result = multiply(num1, num2);  // Call the multiply function
                break;
            case '/':
                if (num2 != 0) {  // Check for division by zero
                    result = divide(num1, num2);  // Call the divide function
                } else {
                    cout << "Error: Division by zero!" << endl;
                    continue;  // Skip the rest of the loop and prompt the user again
                }
                break;
            default:
                cout << "Invalid operation!" << endl;  // Handle invalid operations
                continue;  // Skip the rest of the loop and prompt the user again
        }

        cout << "Result: " << result << endl;  // Output the result
    }

    return 0;  // Return 0 to indicate successful completion
}

// Function to display the menu
void showMenu() {
    cout << "Simple Calculator" << endl;
    cout << "-----------------" << endl;
    cout << "Options:" << endl;
    cout << " + : Addition" << endl;
    cout << " - : Subtraction" << endl;
    cout << " * : Multiplication" << endl;
    cout << " / : Division" << endl;
    cout << " q : Quit" << endl;
    cout << "-----------------" << endl;
}

// Function to add two numbers
double add(double a, double b) {
    return a + b;  // Return the sum of a and b
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;  // Return the difference of a and b
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;  // Return the product of a and b
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;  // Return the quotient of a and b
}


// to compile do
// g++ -o calculator calculator.cpp