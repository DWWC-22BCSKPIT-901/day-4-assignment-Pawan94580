Ques 5. You are given an integer array nums and an integer k.
Find the longest subsequence of nums that meets the following requirements:
●	The subsequence is strictly increasing and
●	The difference between adjacent elements in the subsequence is at most k.
Return the length of the longest subsequence that meets the requirements.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Program Code:
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int longestSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && nums[i] - nums[j] <= k) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    int k = 3;
    cout << longestSubsequence(nums, k) << endl;  
    return 0;
}
