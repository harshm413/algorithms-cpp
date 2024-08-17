#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Helper function to calculate the minimum steps to reduce n to 1 using memoization
int minStepsToOneMemo(int n, vector<int>& memo) {
    // Base case: if n is 1, no more steps are needed
    if (n == 1) {
        return 0;
    }
    
    // If the result is already computed, return it
    if (memo[n] != -1) {
        return memo[n];
    }

    // Initialize the minimum steps with maximum possible value
    int steps = INT_MAX;

    // Option 1: Subtract 1
    steps = min(steps, 1 + minStepsToOneMemo(n - 1, memo));

    // Option 2: Divide by 2 (if n is divisible by 2)
    if (n % 2 == 0) {
        steps = min(steps, 1 + minStepsToOneMemo(n / 2, memo));
    }

    // Option 3: Divide by 3 (if n is divisible by 3)
    if (n % 3 == 0) {
        steps = min(steps, 1 + minStepsToOneMemo(n / 3, memo));
    }

    // Store the result in the memo array
    memo[n] = steps;
    
    return steps;
}

int minStepsToOne(int n) {
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    return minStepsToOneMemo(n, memo);
}

int main() {
    int n = 10; // Example number to reduce to 1
    int result = minStepsToOne(n);

    cout << "Minimum steps to reduce " << n << " to 1 is: " << result << endl;

    return 0;
}
