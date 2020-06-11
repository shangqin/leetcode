#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

class Solution1 {
public:
    int calculate(string& s)
    {
        stack<int> st;
        int temp = 0; //记录多位数
        int result = 0; //记录压入栈的数字
        int symbol = 1; //标志正负数

        for (int i = 0; i < s.size(); i++) {
            printf("s[i] = %c\n", s[i]);
            if (s[i] >= '0'&& s[i] <= '9') {
                temp = 10 * temp + (s[i] - '0');
                printf("temp = %d\n", temp);
            } else if (s[i] == '+') {
                result += symbol * temp;
                printf("+: symbol = %d, temp = %d, result = %d\n", symbol, temp, result);
                symbol = 1; //重置
                temp = 0; //重置
            } else if (s[i] == '-') {
                result += symbol * temp;
                printf("+: symbol = %d, temp = %d, result = %d\n", symbol, temp, result);
                symbol = -1; //负数
                temp = 0;
            } else if (s[i] == '(') {
                printf("(: push result = %d, symbol = %d\n", result, symbol);
                st.push(result);
                st.push(symbol);
                symbol = 1;
                result = 0;
            } else if (s[i] == ')') {
                result += symbol * temp;//计算括号内的结果
                printf("): symbol = %d, temp = %d, result = %d\n", symbol, temp, result);

                printf("+: pop %d, result = %d\n", st.top(), result);
                result *= st.top();
                st.pop();//获取入栈前的正负号

                printf("+: pop %d, result = %d\n", st.top(), result);
                result += st.top();
                st.pop();//加上入栈前的结果

                temp = 0;//重置，因为)之前是数字，temp还是不变
            }
            printf("\n");
        }

        //循环退出的时候，肯定最后一个是数字（合法表达式），要把result加上该数字，而且别忘了倒数第二位的正负号
        printf("out: symbol = %d, temp = %d, result = %d\n", symbol, temp, result);
        return result + (symbol * temp);
    }
};

class Solution {
public:
    int calculate(string& s)
    {
        stack<int> st;
        int temp = 0; //记录多位数
        int result = 0; //记录压入栈的数字
        int symbol = 1; //标志正负数

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0'&& s[i] <= '9') {
                temp = 10 * temp + (s[i] - '0');
            } else if (s[i] == '+') {
                result += symbol * temp;
                symbol = 1;
                temp = 0;
            } else if (s[i] == '-') {
                result += symbol * temp;
                symbol = -1;
                temp = 0;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(symbol);
                symbol = 1;
                result = 0;
            } else if (s[i] == ')') {
                result += symbol * temp;

                result *= st.top();
                st.pop(); //获取入栈前的正负号

                result += st.top();
                st.pop(); //加上入栈前的结果

                temp = 0; //重置，因为)之前是数字，temp还是不变
            }
        }

        //循环退出的时候，肯定最后一个是数字（合法表达式），要把result加上该数字，而且别忘了倒数第二位的正负号
        return result + (symbol * temp);
    }
};

int main()
{
    {
        string s = "(1+(4+5+2)-3)+(6+8)";
        cout << Solution().calculate(s) << endl;
        cout << "The result should be 23" << endl;
    }

    return 0;
}
