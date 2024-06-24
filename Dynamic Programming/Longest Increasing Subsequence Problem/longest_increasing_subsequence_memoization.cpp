#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Recursive function with memoization to find the length of LIS
int lisMemo(vector<int>& nums, int n, vector<int>& memo) {
    // Base case: if only one element is present
    if (n == 1) {
        return 1;
    }

    // If result is already computed, return it from memoization table
    if (memo[n] != -1) {
        return memo[n];
    }

    int maxEndingHere = 1; // Length of LIS ending at current element

    // Recursively find LIS ending at previous elements and update maxEndingHere
    for (int i = 1; i < n; ++i) {
        int subproblem = lisMemo(nums, i, memo);
        if (nums[i - 1] < nums[n - 1]) {
            maxEndingHere = max(maxEndingHere, 1 + subproblem);
        }
    }

    return memo[n] = maxEndingHere;
}

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    // Initialize memoization table with -1
    vector<int> memo(n + 1, -1);

    return lisMemo(nums, n, memo);
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18}; // Example array

    int lisLength = longestIncreasingSubsequence(nums);

    cout << "Length of Longest Increasing Subsequence is: " << lisLength << endl;

    return 0;
}
