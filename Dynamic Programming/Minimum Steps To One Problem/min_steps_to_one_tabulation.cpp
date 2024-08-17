#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Function to calculate the minimum steps to reduce n to 1 using dynamic programming (tabulation)
int minStepsToOne(int n) {
    // Create a DP array to store the minimum steps for each number from 1 to n
    vector<int> dp(n + 1, INT_MAX); // Initialize the dp array with INT_MAX
    
    // Base case: it takes 0 steps to reduce 1 to 1
    dp[1] = 0;

    // Fill the dp array for each number from 2 to n
    for (int i = 2; i <= n; ++i) {
        // Option 1: Subtract 1
        dp[i] = 1 + dp[i - 1];
        
        // Option 2: Divide by 2 (if i is divisible by 2)
        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }

        // Option 3: Divide by 3 (if i is divisible by 3)
        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
    }

    // Return the minimum steps to reduce n to 1
    return dp[n];
}

int main() {
    int n = 10; // Example number to reduce to 1
    int result = minStepsToOne(n);

    cout << "Minimum steps to reduce " << n << " to 1 is: " << result << endl;

    return 0;
}
