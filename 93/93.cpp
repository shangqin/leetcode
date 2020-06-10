#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int CheckValid(const string& s)
    {
        int value = 0;
        for (int i = 0; i < s.size(); ++i) {
            value = value * 10 + (s[i] - '0');
        }

        int ret = 0;
        if ((value >= 0) && (value <= 255)) {
            ret = 1;
        }

        cout << s << ", valid = " << ret << endl;
        return ret;
    }

    int GetCount(const string& s, int dotCount)
    {
        if (s.size() <= 3) {
            return 0;
        }

        int count = CheckValid(s.substr(0, 1)) * GetCount(s.substr(1, s.size() - 1)) +
                  CheckValid(s.substr(0, 2)) * GetCount(s.substr(2, s.size() - 2)) +
                  CheckValid(s.substr(0, 3)) * GetCount(s.substr(3, s.size() - 3));

        cout << s << ", count = " << count << endl;
        return count;
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ret;
        int count = GetCount(s);
        cout << "count = " << count << endl;
        return ret;
    }
};


// 25525511135
// ret(25525511135) = ret(25525511135) + ret(525511135) + ret(25511135)
//

int main()
{
    {
        string s = "25525511135";
        auto ret = Solution().restoreIpAddresses(s);
        for (auto &i : ret) {
            cout << i << endl;
        }
        cout << endl;

        vector<string> r = {"255.255.11.135", "255.255.111.35"};
        cout << "The result should be" << endl;
        for (auto &i : r) {
            cout << i << endl;
        }
    }

    return 0;
}
