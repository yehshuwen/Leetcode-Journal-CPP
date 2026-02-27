#include <cctype>
#include <string>
/*
8. String to Integer (atoi)
*/
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int res = 0;

        while(i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.size() && isdigit(s[i])){
            int digit = s[i] - '0';
            if (res > INT_MAX/10 || (res == INT_MAX/10 && digit>7)){
                return (sign == 1) ? INT_MAX: INT_MIN; // 2,147,483,647 or -2,147,483,648
            }
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};