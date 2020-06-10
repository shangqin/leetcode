#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cur;
        DFS(s,cur,res);
        return res;
    }

    bool IsPalindrome(const string& s)
    {
        return s == string(s.rbegin(), s.rend());
    }

    void DFS(const string& s, vector<string>& cur, vector<vector<string>>& res)
    {
        if (s == "") {
            res.push_back(cur);
            return;
        }

        for (int i = 1; i <= s.length(); ++i) {
            string sub = s.substr(0, i);
            if (IsPalindrome(sub)){
                cur.push_back(sub);
                DFS(s.substr(i, s.length() - i), cur, res);
                cur.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cur;
        DFS(s,cur,res);
        return res;
    }

    bool IsPalindrome(const string& s)
    {
        auto iter = map.find(s);
        if (iter != map.end()) {
            return iter->second;
        }

        int start = 0;
        int end = static_cast<int>(s.size()) - 1;
        bool res = true;

        while (start < end) {
            if (s[start] != s[end]) {
                res = false;
                break;
            }

            start++;
            end--;
        }

        map[s] = res;
        return res;
    }

    void DFS(const string& s, vector<string>& cur, vector<vector<string>>& res)
    {
        if (s == "") {
            res.push_back(cur);
            return;
        }

        for (int i = 1; i <= s.length(); ++i) {
            string sub = s.substr(0, i);
            if (IsPalindrome(sub)) {
                cur.push_back(sub);
                DFS(s.substr(i, s.length() - i), cur, res);
                cur.pop_back();
            }
        }
    }

private:
    unordered_map<string, bool> map;
};

int main()
{
    {
        string s = "aab";
        auto res = Solution().partition(s);
        for (auto& i : res) {
            for (auto & j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
