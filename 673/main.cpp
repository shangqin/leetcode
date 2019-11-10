#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
673. 最长递增子序列的个数
https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
*/

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int ret = 0;

        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLen = 0;
        int maxLenIndex = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxLenIndex = i;
            }
        }

        if (maxLen == 1) {
            return dp.size();
        } else {
            for (int i = maxLenIndex - 1; i >=0; --i) {
                if (dp[i] == maxLen - 1) {
                    ++ret;
                } else {
                    break;
                }
            }
        }


        return ret;
    }
};

int main() {
//    vector<int> nums = {1, 3, 5, 4, 7};
//    vector<int> nums = {2, 2, 2, 2, 2};
    vector<int> nums = {1, 2, 4, 3, 5, 4, 7, 2};
    int ret = Solution().findNumberOfLIS(nums);
    cout << ret << endl;

    return 0;
}