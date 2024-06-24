#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    vector<int> dp(n, 1); // dp[i] will store the length of LIS ending at index i

    // Build the DP table in bottom-up manner
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end()); // Return the maximum value in dp array
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18}; // Example array

    int lisLength = longestIncreasingSubsequence(nums);

    cout << "Length of Longest Increasing Subsequence is: " << lisLength << endl;

    return 0;
}
