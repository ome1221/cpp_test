#include <iostream>

using namespace std;

// Macro
#define ABS(x) ((x) < 0 ? -(x) : (x))

int main() {
    int num = -10;
    int absoluteValue = ABS(num);

    cout << "Absolute value of " << num << " is: " << absoluteValue << endl;

    return 0;
}
