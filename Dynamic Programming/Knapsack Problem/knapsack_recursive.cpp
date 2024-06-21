#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Brute-force recursive function to solve the 0/1 Knapsack problem
double knapsackRecursive(vector<double>& weights, vector<double>& values, double capacity, int n) {
    // Base case: if no items are left or the capacity is 0
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If weight of the nth item is more than the capacity, it cannot be included
    if (weights[n - 1] > capacity) {
        return knapsackRecursive(weights, values, capacity, n - 1);
    }

    // Return the maximum value obtained by either including or excluding the nth item
    return max(
        values[n - 1] + knapsackRecursive(weights, values, capacity - weights[n - 1], n - 1),
        knapsackRecursive(weights, values, capacity, n - 1)
    );
}

int main() {
    vector<double> weights = {1, 5, 20, 35, 90}; // Weights of items
    vector<double> values = {15, 14.5, 19.2, 19.8, 195.2}; // Values of items
    double capacity = 20; // Capacity of the knapsack

    int n = weights.size(); // Number of items

    double maxValue = knapsackRecursive(weights, values, capacity, n);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
