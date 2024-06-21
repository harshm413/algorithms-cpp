#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Function to calculate the maximum profit recursively
double rodCutting(vector<int>& lengths, vector<double>& prices, int n) {
    // Base case: if rod length is 0, profit is 0
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MIN; // If n is negative, return INT_MIN
    }
    
    double maxProfit = INT_MIN; // Initialize max profit with minimum possible value

    // Recursively calculate the maximum profit by considering all possible cuts
    for (int i = 0; i < lengths.size(); ++i) {
        maxProfit = max(maxProfit, prices[i] + rodCutting(lengths, prices, n - lengths[i]));
    }
    
    maxProfit = max(maxProfit, 0.0); // Consider the case where we waste the entire rod

    return maxProfit;
}

int main() {
    vector<int> lengths = {1, 3, 5, 10, 30, 50, 75}; // Allowed lengths for cutting
    vector<double> prices = {0.1, 0.2, 0.4, 0.9, 3.1, 5.1, 8.2}; // Prices corresponding to each length

    int rodLength = 30; // Example rod length to cut
    double maxProfit = rodCutting(lengths, prices, rodLength);

    cout << "Maximum profit for rod of length " << rodLength << " is: " << maxProfit << endl;

    return 0;
}
