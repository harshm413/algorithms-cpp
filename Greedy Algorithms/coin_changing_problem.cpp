#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coinChange(vector<int>& denominations, int amount) {
    sort(denominations.rbegin(), denominations.rend());

    vector<int> result;

    for (int coin : denominations) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }

    return result;
}

int main() {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int amount = 2896;
    vector<int> result = coinChange(denominations, amount);

    cout << "Coins used:\n";
    for (int coin : result) {
        cout << coin << " ";
    }
    return 0;
}