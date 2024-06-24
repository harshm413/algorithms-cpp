#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    vector<int> dp(n + 1, 0); // dp[i] will store the maximum amount that can be robbed up to index i

    dp[1] = nums[0]; // Base case for the first house

    // Build the DP table in bottom-up manner
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }

    return dp[n]; // Return the maximum value in dp array
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // Example array of house values

    int maxAmount = rob(nums);

    cout << "Maximum amount that can be robbed is: " << maxAmount << endl;

    return 0;
}
