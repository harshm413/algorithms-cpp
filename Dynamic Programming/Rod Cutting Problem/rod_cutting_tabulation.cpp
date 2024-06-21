#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Function to calculate the maximum profit using dynamic programming (tabulation)
double rodCutting(vector<int>& lengths, vector<double>& prices, int n) {
    // Create a DP array to store maximum profit for each rod length from 0 to n
    vector<double> dp(n + 1, 0); // Bottom-up approach: initialize dp array with size n+1 filled with 0

    // Calculate maximum profit for each rod length up to n
    for (int i = 1; i <= n; ++i) {
        double maxProfit = INT_MIN;
        for (int j = 0; j < lengths.size(); ++j) {
            if (i >= lengths[j]) { // Only consider valid cuts where i >= lengths[j]
                maxProfit = max(maxProfit, prices[j] + dp[i - lengths[j]]);
            }
        }
        dp[i] = maxProfit; // Store the maximum profit for rod length i
    }

    return dp[n]; // Return maximum profit for rod of length n
}

int main() {
    vector<int> lengths = {1, 3, 5, 10, 30, 50, 75}; // Allowed lengths for cutting
    vector<double> prices = {0.1, 0.2, 0.4, 0.9, 3.1, 5.1, 8.2}; // Prices corresponding to each length

    int rodLength = 300; // Example rod length to cut
    double maxProfit = rodCutting(lengths, prices, rodLength);

    cout << "Maximum profit for rod of length " << rodLength << " is: " << maxProfit << endl;

    return 0;
}
