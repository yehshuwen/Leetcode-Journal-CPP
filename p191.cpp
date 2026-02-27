/*
191. Number of 1 Bits
給你一個平常我們看的數字（例如 11），請你告訴電腦，如果把它換成二進位，裡面會有幾個 「1」？
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }
        return count;
    }
};