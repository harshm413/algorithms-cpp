#include <iostream>
#include <vector>

using namespace std;

// Recursive function with memoization to count ways to reach the nth step
int climbStairsMemo(int n, vector<int>& memo) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }

    // If result is already computed, return it from memoization table
    if (memo[n] != -1) {
        return memo[n];
    }

    // Recursive step
    memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
    return memo[n];
}

int climbStairs(int n) {
    // Initialize memoization table with -1
    vector<int> memo(n + 1, -1);
    return climbStairsMemo(n, memo);
}

int main() {
    int n = 3; // Example number of steps
    cout << "Number of ways to climb " << n << " steps is: " << climbStairs(n) << endl;
    return 0;
}
