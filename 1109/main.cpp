#include <iostream>
#include <vector>
using namespace std;

// 超出时间限制
// 47 / 63 个通过测试用例
//class Solution {
//public:
//    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//        vector<int> ret(n, 0);
//
//        for (auto &data: bookings) {
//            for (int i=data[0]-1; i<data[1]; ++i) {
//                ret[i] += data[2];
//            }
//        }
//
//        return ret;
//    }
//};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n, 0);
        vector<int> delta(n + 2, 0);

        for (auto &data: bookings) {
            delta[data[0]] += data[2];
            delta[data[1] + 1] -= data[2];
        }

        ret[0] = delta[1];
        for (int i=1; i<n; ++i) {
            ret[i] = ret[i - 1] + delta[i + 1];
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> bookings = {
            {1, 2, 10},
            {2, 3, 20},
            {2, 5, 25}
    };

    auto ret = Solution().corpFlightBookings(bookings, 5);
    for (auto &i: ret) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}