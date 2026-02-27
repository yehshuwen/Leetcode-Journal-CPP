#include <string>

using namespace std;
/*
125. Valid Palindrome
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()== 0) return true;
        int head = 0;
        int tail = s.size()-1;
        while(head < tail) {
            if (!isalnum(s[head])) {
                head ++;
            } else if (!isalnum(s[tail])){
                tail --;
            } else {
                if (tolower(s[head]) != tolower(s[tail])) {
                    return false;
                }
                head ++;
                tail --;
            }
        }
        return true;
    }
};