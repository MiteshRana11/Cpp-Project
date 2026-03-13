#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) { return b != 0 ? a / b : 0; }
};

int main() {

    Calculator calc;
    int choice;
    double num1, num2;

    while(true){

        cout << "\n=== SIMPLE CALCULATOR ===\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 5) break;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch(choice){
            case 1: cout << "Result: " << calc.add(num1,num2); break;
            case 2: cout << "Result: " << calc.subtract(num1,num2); break;
            case 3: cout << "Result: " << calc.multiply(num1,num2); break;
            case 4: cout << "Result: " << calc.divide(num1,num2); break;
            default: cout << "Invalid choice";
        }
    }

    return 0;
}