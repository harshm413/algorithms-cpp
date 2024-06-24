#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Recursive function to find the maximum amount that can be robbed
int robRecursive(vector<int>& nums, int n) {
    // Base case: if no houses are left
    if (n == 0) {
        return 0;
    }

    // If only one house is left, return its value
    if (n == 1) {
        return nums[0];
    }

    // Rob current house and skip next house, or skip current house
    return max(nums[n - 1] + robRecursive(nums, n - 2), robRecursive(nums, n - 1));
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // Example array of house values

    int n = nums.size();

    int maxAmount = robRecursive(nums, n);

    cout << "Maximum amount that can be robbed is: " << maxAmount << endl;

    return 0;
}
