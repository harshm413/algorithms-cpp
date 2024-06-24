#include <iostream>

using namespace std;

// Recursive function to count ways to reach the nth step
int climbStairsRecursive(int n) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive step
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

int main() {
    int n = 3; // Example number of steps
    cout << "Number of ways to climb " << n << " steps is: " << climbStairsRecursive(n) << endl;
    return 0;
}
