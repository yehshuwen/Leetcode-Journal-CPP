#include<vector>
#include<queue>


using namespace std;
/*
210. Course Schedule II
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites [[1,0],[2,0],[3,1],[3,2]]
        vector<vector<int>> adj(numCourses); // if numCourses = 4 [[],[],[],[]]
        vector<int> indegree(numCourses, 0); //[0,0,0,0]
        vector<int> result;

        for(auto& pre: prerequisites) {
            int course = pre[0];
            int preCourse = pre[1];
            adj[preCourse].push_back(course); // preCourse -> course
            indegree[course]++; // [0, 1, 1, 2]
            //adj  0: [1, 2] 1: [3] 2: [3]
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            // 不用先修課可以直接上
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr =  q.front(); // Queue FIFO
            q.pop();
            result.push_back(curr);
            for (int nextCourse: adj[curr]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        if (result.size() == numCourses) return result;
        return {};
    }
};