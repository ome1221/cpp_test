#include <iostream>

using namespace std;

// Macro to determine the greater of two numbers using conditional operator
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int num1 = 10, num2 = 20;
    int maximum = MAX(num1, num2);

    cout << "The greater of " << num1 << " and " << num2 << " is: " << maximum << endl;

    return 0;
}
