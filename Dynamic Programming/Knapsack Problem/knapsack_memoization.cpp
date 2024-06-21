#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Helper function to solve the 0/1 Knapsack problem using memoization
double knapsackMemo(vector<int>& weights, vector<double>& values, int capacity, int n, vector<vector<double>>& memo) {
    // Base case: if no items are left or the capacity is 0
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // Return the stored value if the subproblem has already been solved
    if (memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    // If weight of the nth item is more than the capacity, it cannot be included
    if (weights[n - 1] > capacity) {
        return memo[n][capacity] = knapsackMemo(weights, values, capacity, n - 1, memo);
    }

    // Return the maximum value obtained by either including or excluding the nth item
    return memo[n][capacity] = max(
        values[n - 1] + knapsackMemo(weights, values, capacity - weights[n - 1], n - 1, memo),
        knapsackMemo(weights, values, capacity, n - 1, memo)
    );
}

double knapsack(vector<int>& weights, vector<double>& values, int capacity) {
    int n = weights.size(); // Number of items
    vector<vector<double>> memo(n + 1, vector<double>(capacity + 1, -1)); // Memoization table
    return knapsackMemo(weights, values, capacity, n, memo);
}

int main() {
    vector<int> weights = {1, 5, 20, 35, 90}; // Weights of items
    vector<double> values = {15, 14.5, 19.2, 19.8, 195.2}; // Values of items
    int capacity = 200; // Capacity of the knapsack

    double maxValue = knapsack(weights, values, capacity);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
