#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Brute-force recursive function to calculate the minimum coins
int minCoinsRecursive(vector<int>& coins, int amount) {
    // Base case: if amount is 0, no coins are needed
    if (amount == 0) {
        return 0;
    }
    // If amount is negative, return INT_MAX (impossible situation)
    if (amount < 0) {
        return INT_MAX;
    }

    int minCoins = INT_MAX;

    // Try every coin and find the minimum number of coins needed
    for (int coin : coins) {
        int res = minCoinsRecursive(coins, amount - coin);
        if (res != INT_MAX) {
            minCoins = min(minCoins, res + 1);
        }
    }

    return minCoins;
}

int coinChange(vector<int>& coins, int amount) {
    int result = minCoinsRecursive(coins, amount);
    return result == INT_MAX ? -1 : result;
}

int main() {
    vector<int> coins = {1, 4, 7, 9, 16, 43};
    int amount = 17;
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Amount cannot be made up by any combination of the given coins." << endl;
    }

    return 0;
}
