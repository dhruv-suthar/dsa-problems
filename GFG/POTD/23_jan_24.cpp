/*
Course Schedule

The problem involves finding a valid ordering of tasks to complete, given a set of prerequisite pairs. Each task is labeled from 0 to n-1, and some tasks have dependencies, expressed as pairs [x, y], meaning that task x must be completed before task y. The goal is to determine a valid order in which to complete the tasks.

If a valid ordering exists, the algorithm should return any one of the possible correct orders. If it's impossible to finish all tasks due to cyclic dependencies or other reasons, the algorithm should return an empty array. The presence of a valid ordering is indicated by the output being 1, while an invalid order results in the output being 0. The driver code will print "No Ordering Possible" for an empty array.

In summary, the task involves solving a directed graph problem where the nodes represent tasks, and the edges represent dependencies between tasks. The algorithm needs to find a topological ordering of the tasks, ensuring that prerequisites are completed before dependent tasks.

Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases. One possible order is [0, 1].

Example 2:

Input:
n = 4, m = 4
prerequisites = {{1, 0},
               {2, 0},
               {3, 1},
               {3, 2}}
Output:
1
Explanation:
There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of 1.

*/

class Solution
{
    public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> g(n);
        vector<int> in(n, 0);
        
        for(int i = 0; i < m; i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++in[prerequisites[i][0]];
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto child : g[node]){
                --in[child];
                
                if(in[child] == 0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        
        if(ans.size() < n)
            ans.clear();
            
        return ans;
    }
};
