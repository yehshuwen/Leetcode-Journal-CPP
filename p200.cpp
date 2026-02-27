#include<vector>

using namespace std;

/*
200. Number of Islands
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++){
                 if (grid[r][c] == '1'){
                    count++;
                    dfs(grid, r, c);
                 }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        // 超出邊界或是遇到0就停
        // r c 是目前位置 rows cols 是grid邊界
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        //當前土地變成0 避免重複計算
        grid[r][c] = '0';
        
        //從當前掃上下左右
        dfs(grid, r - 1, c); //下
        dfs(grid, r + 1, c); //上
        dfs(grid, r, c - 1); //左
        dfs(grid, r, c + 1); //右
        
    }
};