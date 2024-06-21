#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming (tabulation)
double knapsack(vector<int>& weights, vector<double>& values, int capacity) {
    int n = weights.size(); // Number of items
    vector<vector<double>> dp(n + 1, vector<double>(capacity + 1, 0)); // DP table

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity]; // Maximum value that can be put in a knapsack of capacity
}

int main() {
    vector<int> weights = {1, 5, 20, 35, 90}; // Weights of items
    vector<double> values = {15, 14.5, 19.2, 19.8, 195.2}; // Values of items
    int capacity = 200; // Capacity of the knapsack

    double maxValue = knapsack(weights, values, capacity);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
