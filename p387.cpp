#include <string>
#include <vector>


using namespace std;

/*
387. First Unique Character in a String
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        
        for (char c: s) {
            count[c - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};