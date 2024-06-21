#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Helper function to calculate the maximum profit using memoization
double rodCuttingMemo(vector<int>& lengths, vector<double>& prices, int n, vector<double>& memo) {
    // Base case: if rod length is 0, profit is 0
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MIN; // If n is negative, return INT_MIN
    }
    if (memo[n] != -1) {
        return memo[n]; // Return cached result if available
    }

    double maxProfit = INT_MIN; // Initialize max profit with minimum possible value

    // Recursively calculate the maximum profit by considering all possible cuts
    for (int i = 0; i < lengths.size(); ++i) {
        maxProfit = max(maxProfit, prices[i] + rodCuttingMemo(lengths, prices, n - lengths[i], memo));
    }

    maxProfit = max(maxProfit, 0.0); // Consider the case where we waste the entire rod

    memo[n] = maxProfit; // Store the result in the cache
    return maxProfit;
}

double rodCutting(vector<int>& lengths, vector<double>& prices, int n) {
    vector<double> memo(n + 1, -1); // Initialize memoization array with -1
    return rodCuttingMemo(lengths, prices, n, memo);
}

int main() {
    vector<int> lengths = {1, 3, 5, 10, 30, 50, 75}; // Allowed lengths for cutting
    vector<double> prices = {0.1, 0.2, 0.4, 0.9, 3.1, 5.1, 8.2}; // Prices corresponding to each length

    int rodLength = 300; // Example rod length to cut
    double maxProfit = rodCutting(lengths, prices, rodLength);

    cout << "Maximum profit for rod of length " << rodLength << " is: " << maxProfit << endl;

    return 0;
}
