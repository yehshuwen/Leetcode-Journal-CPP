#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
20. Valid Parentheses
用stack 因為有順序問題 LIFO
([)] 這樣就是錯的
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if(s[i] == '{') {
                st.push('}');
            } else if(s[i] == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != s[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};