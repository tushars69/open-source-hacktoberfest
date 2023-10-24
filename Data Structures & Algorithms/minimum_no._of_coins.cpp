#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); // Initialize a DP array with a large value
    dp[0] = 0; // Base case: 0 coins needed to make change for 0 amount

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = minCoins(coins, amount);

    if (result == -1) {
        cout << "Cannot make change for " << amount << " using the given coins." << endl;
    } else {
        cout << "Minimum number of coins to make change for " << amount << " is: " << result << endl;
    }

    return 0;
}
