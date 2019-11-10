#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 10, 9, 2, 5, 3, 7, 101, 18动态规划，最长递增子序列
 * 300 -- 基础，求最长递增子序列的长度
 * 673 -- 升级版，求最长递增子序列的个数
 *
 * 300. 最长上升子序列
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 示例:
 *
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 说明:
 *
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n2) 。
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * */

/*
 * 使用归纳的方法，找到状态转移方程
 * dp[i] 表示nums[i]这个数结尾的最长递增子序列的长度
 * i:     0,  1, 2, 3, 4, 5, 6,   7
 * nums:  10, 9, 2, 5, 3, 7, 101, 18
 * dp[i]: 1,  1, 1, 2, 2, 3, 4,   4
 * 所以最长递增子序列的长度为4
 *
 * 状态转移方程：
 * dp[i] = max(dp[j]) + 1,∀0≤j<i  前面所有小于nums[i]的数的dp值的最大值，然后+1
 * 举例：
 * 上面例子中的dp[5]，值为7，找到前面小于7的值，有2，5，3共3个数
 * 2的dp值是1，5的dp值是2，3的dp值是2，最大值是2，所以值为7的dp值是3
 * */

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // 1，考虑特殊场景
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        }

        vector<int> dp(nums.size(), 1);

        // 2，计算所有数值的dp值，同时记录最大值
        int maxLen = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }

        }

        return maxLen;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ret = Solution().lengthOfLIS(nums);
    cout << ret << endl;

    return 0;
}