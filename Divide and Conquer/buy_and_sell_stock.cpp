#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum crossing profit
int maxCrossingProfit(vector<int>& prices, int left, int mid, int right) {
    // Find the minimum price in the left half
    int min_price = INT_MAX;
    for (int i = left; i <= mid; ++i) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
    }

    // Find the maximum price in the right half
    int max_price = INT_MIN;
    for (int i = mid + 1; i <= right; ++i) {
        if (prices[i] > max_price) {
            max_price = prices[i];
        }
    }

    // Return the maximum profit possible by buying in the left half and selling in the right half
    return max_price - min_price;
}

// Function to find the maximum profit using divide and conquer
int maxProfit(vector<int>& prices, int left, int right) {
    // Base case: if there's only one price or no prices
    if (left >= right) {
        return 0;
    }

    // Find the middle point
    int mid = left + (right - left) / 2;

    // Find the maximum profit in left half, right half, and across the mid
    return max(maxProfit(prices, left, mid),
                max(maxProfit(prices, mid + 1, right),
                maxCrossingProfit(prices, left, mid, right)));
}

int main() {
    vector<int> prices = {2,4,8,1,10};
    int max_profit = maxProfit(prices, 0, prices.size() - 1);
    cout << "Maximum profit is: " << max_profit << endl;

    return 0;
}
