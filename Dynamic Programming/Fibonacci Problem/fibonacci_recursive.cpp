#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Recursively calculate Fibonacci(n) as Fibonacci(n-1) + Fibonacci(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Example nth number to calculate Fibonacci
    int fibValue = fibonacci(n);

    cout << "Fibonacci of " << n << " is: " << fibValue << endl;

    return 0;
}
