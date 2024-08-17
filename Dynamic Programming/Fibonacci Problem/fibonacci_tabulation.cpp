#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number using dynamic programming (tabulation)
int fibonacci(int n) {
    // Create a DP array to store Fibonacci values up to n
    vector<int> dp(n + 1, 0); // Initialize dp array with size n+1 filled with 0
    
    // Base cases: F(0) = 0, F(1) = 1
    if (n >= 1) {
        dp[1] = 1;
    }

    // Fill the DP table for Fibonacci numbers from 2 to n
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // F(i) = F(i-1) + F(i-2)
    }

    return dp[n]; // Return Fibonacci number at index n
}

int main() {
    int n = 30; // Example nth number to calculate Fibonacci
    int fibValue = fibonacci(n);

    cout << "Fibonacci of " << n << " is: " << fibValue << endl;

    return 0;
}
