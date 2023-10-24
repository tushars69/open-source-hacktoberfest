#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    int maxRobbedAmount = rob(nums);

    cout << "Maximum amount that can be robbed is: " << maxRobbedAmount << endl;

    return 0;
}
