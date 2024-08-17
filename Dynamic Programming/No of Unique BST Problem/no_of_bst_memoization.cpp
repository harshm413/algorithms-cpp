#include <iostream>
#include <vector>

using namespace std;

// Helper function to calculate the number of unique BSTs using memoization
int numOfUniqueBSTMemo(int n, vector<int>& memo) {
    // Base case: for 0 or 1 nodes, there is only 1 unique BST
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n]; // Return cached result if available
    }

    // Initialize total count for BSTs
    int totalBSTs = 0;

    // Recursively calculate the number of unique BSTs using the Catalan number formula
    for (int i = 1; i <= n; ++i) {
        totalBSTs += numOfUniqueBSTMemo(i - 1, memo) * numOfUniqueBSTMemo(n - i, memo);
    }

    memo[n] = totalBSTs; // Store the result in the memo array
    return totalBSTs;
}

// Main function to calculate the number of unique BSTs for 'n' nodes
int numOfUniqueBST(int n) {
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    return numOfUniqueBSTMemo(n, memo);
}

int main() {
    int n = 7; // Example: find the number of unique BSTs for n nodes
    int uniqueBSTs = numOfUniqueBST(n);

    cout << "Number of unique BSTs for " << n << " nodes is: " << uniqueBSTs << endl;

    return 0;
}
