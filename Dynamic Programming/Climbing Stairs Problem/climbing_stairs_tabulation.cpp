#include <iostream>
#include <vector>

using namespace std;

// Function to count ways to reach the nth step using tabulation
int climbStairsTabulation(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    // Create a table to store results of subproblems
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    // Fill the table from the bottom up
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 3; // Example number of steps
    cout << "Number of ways to climb " << n << " steps is: " << climbStairsTabulation(n) << endl;
    return 0;
}
