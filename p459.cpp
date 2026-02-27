#include <string>
#include <unordered_map>

using namespace std;
/*
2. LeetCode 459. Repeated Substring Pattern
題目會給你一個字串，問你它是否是由某個「子字串」重複多次構成的。

練習重點：你需要去嘗試各種不同長度 M 的子字串。

與 N−M 的關聯：如果你假設子字串長度是 M，你就會用到類似的跳躍邏輯來比對。

思考點：如果一個字串能被重複構成，那 M 一定是 N 的因數。
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size()/2; i++){
            if (s.size() % i ==0){
                string pattern = s.substr(0, i);
                string reconstructed = "";

                int repeats = s.size()/i;
                for (int j = 0; j < repeats; j++) {
                    reconstructed += pattern;
                }
                if (reconstructed == s) return true;
            }
            
        }
        return false;

    }
};