#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Recursive function with memoization to find the maximum amount that can be robbed
int robMemo(vector<int>& nums, int n, vector<int>& memo) {
    // Base case: if no houses are left
    if (n <= 0) {
        return 0;
    }

    // If result is already computed, return it from memoization table
    if (memo[n] != -1) {
        return memo[n];
    }

    return memo[n] = max(nums[n - 1] + robMemo(nums, n - 2, memo), robMemo(nums, n - 1, memo));
}

int rob(vector<int>& nums) {
    int n = nums.size();

    // Initialize memoization table with -1
    vector<int> memo(n + 1, -1);

    return robMemo(nums, n, memo);
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // Example array of house values

    int maxAmount = rob(nums);

    cout << "Maximum amount that can be robbed is: " << maxAmount << endl;

    return 0;
}
