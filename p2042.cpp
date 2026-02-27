#include <string>
#include <cctype>

using namespace std;

/*
2042. Check if Numbers Are Ascending in a Sentence
*/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int i = 0;
        while (i < s.size()) {
            if(isdigit(s[i])) {
                int currentNum = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    currentNum = currentNum*10 + (s[i] - '0');
                    i++;
                }
                if (currentNum <= prev) return false;
                prev = currentNum;
            } else {
                i++;
            }
        }
        return true;
    }
};