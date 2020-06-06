#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        if ((size == 0) || (size == 1)) {
            return s;
        }

        vector<vector<bool>> dp(size, vector<bool>(size));
        int start = 0;
        int maxCount = 1;

        // init
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true;
            if ((i + 1 < size) && (s[i] == s[i + 1])) {
                dp[i][i + 1] = true;
                start = i;
                maxCount = 2;
            }
        }

        // check len from 3 to size
        for (int l = 3; l <= size; ++l) {
            for (int i = 0; i + l - 1 < s.size(); ++i) {
                int j = i + l - 1;
                if ((s[i] == s[j]) && (dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (l > maxCount) {
                        start = i;
                        maxCount = l;
                    }
                }
            }
        }

        return s.substr(start, maxCount);
    }
};

int main()
{
    cout << Solution().longestPalindrome("babad") << ", should be bab or aba"<< endl;
    cout << Solution().longestPalindrome("cbbd") << ", should be bb"<< endl;

    return 0;
}
