#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of unique BSTs using dynamic programming (tabulation)
int numOfUniqueBST(int n) {
    // Create a DP array to store the number of unique BSTs for each number of nodes from 0 to n
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = 1; // There's 1 unique BST for 0 nodes (empty tree)
    dp[1] = 1; // There's 1 unique BST for 1 node

    // Calculate the number of unique BSTs for each number of nodes from 2 to n
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            // dp[i] is the sum of all possible combinations of left and right subtrees
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n]; // Return the number of unique BSTs for n nodes
}

int main() {
    int n = 7; // Example: find the number of unique BSTs for n nodes
    int uniqueBSTs = numOfUniqueBST(n);

    cout << "Number of unique BSTs for " << n << " nodes is: " << uniqueBSTs << endl;

    return 0;
}
