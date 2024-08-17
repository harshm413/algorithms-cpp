#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

// Function to calculate the minimum steps to reduce n to 1 recursively
int minStepsToOne(int n) {
    // Base case: if n is 1, no more steps are needed
    if (n == 1) {
        return 0;
    }

    // Initialize the minimum steps with maximum possible value
    int steps = INT_MAX;

    // Option 1: Subtract 1
    steps = min(steps, 1 + minStepsToOne(n - 1));

    // Option 2: Divide by 2 (if n is divisible by 2)
    if (n % 2 == 0) {
        steps = min(steps, 1 + minStepsToOne(n / 2));
    }

    // Option 3: Divide by 3 (if n is divisible by 3)
    if (n % 3 == 0) {
        steps = min(steps, 1 + minStepsToOne(n / 3));
    }

    return steps;
}

int main() {
    int n = 10; // Example number to reduce to 1
    int result = minStepsToOne(n);

    cout << "Minimum steps to reduce " << n << " to 1 is: " << result << endl;

    return 0;
}
