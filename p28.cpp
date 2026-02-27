#include <string>

using namespace std;

/*
1. LeetCode 28. Find the Index of the First Occurrence in a String
這題跟我們剛才寫的題目一模一樣！它是 LeetCode 裡的經典題。

練習重點：練習把剛才討論的優化邊界 j <= n - m 直接實作出來。

相似點：實作 strstr()。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if (l1 < l2) return -1;

        for (int i = 0; i < l1-l2+1; i++) {
            string s = haystack.substr(i, l2);
            if (s == needle) {
                return i;
            }
        }
        return -1;
    }
};