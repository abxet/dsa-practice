#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long res = 0;
        int sign = 1;

        stack<long long> st;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '+') {
                res += num * sign;
                num = 0;
                sign = 1;
            } 
            else if (c == '-') {
                res += num * sign;
                num = 0;
                sign = -1;
            } 
            else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } 
            else if (c == ')') {
                res += num * sign;
                num = 0;

                long long prev_sign = st.top(); st.pop();
                long long prev_res = st.top(); st.pop();

                res = prev_res + prev_sign * res;
            }
        }

        // last number
        res += num * sign;

        return (int)res;
    }
};

int main() {
    Solution a;
    int result = a.calculate("12+2");
    cout << result;
    return 0;
}