#include <iostream>
#include <vector>

using namespace std;

int maxRodCut(int length, int x, int y, int z) {
    vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; i++) {
        int maxVal = INT_MIN;

        // Check if we can make a cut of length x and get the maximum value
        if (i >= x) {
            maxVal = max(maxVal, dp[i - x] + 1);
        }

        // Check if we can make a cut of length y and get the maximum value
        if (i >= y) {
            maxVal = max(maxVal, dp[i - y] + 1);
        }

        // Check if we can make a cut of length z and get the maximum value
        if (i >= z) {
            maxVal = max(maxVal, dp[i - z] + 1);
        }

        dp[i] = maxVal;
    }

    return dp[length];
}

int main() {
    int rodLength = 8;
    int x = 2, y = 3, z = 5;

    int maxCuts = maxRodCut(rodLength, x, y, z);

    cout << "Maximum number of cuts: " << maxCuts << endl;

    return 0;
}
