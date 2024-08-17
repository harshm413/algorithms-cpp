#include <iostream>
#include <vector>

using namespace std;

// Helper function to calculate the nth Fibonacci number using memoization
int fibonacciMemo(int n, vector<int>& memo) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n]; // Return cached result if available
    }

    // Recursively calculate Fibonacci(n) and store the result in the cache
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int fibonacci(int n) {
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    return fibonacciMemo(n, memo);
}

int main() {
    int n = 30; // Example nth number to calculate Fibonacci
    int fibValue = fibonacci(n);

    cout << "Fibonacci of " << n << " is: " << fibValue << endl;

    return 0;
}
