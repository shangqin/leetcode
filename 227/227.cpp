#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s)
    {
        long res = 0;
        long curRes = 0;
        long num = 0;
        int n = s.size();
        char op = '+';

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }

            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+':
                        curRes += num;
                        break;
                    case '-':
                        curRes -= num;
                        break;
                    case '*':
                        curRes *= num;
                        break;
                    case '/':
                        curRes /= num;
                        break;
                    default:
                        break;
                }

                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }

                op = c;
                num = 0;
            }
        }

        return res;
    }
};

int main()
{
    {
        string s = "3+2*2*2 + 1";
        cout << Solution().calculate(s) << endl;
    }

    return 0;
}
