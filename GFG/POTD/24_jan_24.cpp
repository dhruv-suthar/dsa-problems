/*
Check if a given graph is tree or not


You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 
1
Explanation: 
Every node is reachable and the graph has no loops, so it is a tree

Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 
0
Explanation: 
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.

*/

class Solution
{
    public:
  void dfs(int start,vector<int>&ls,vector<int> adj[],int arr[]){
        
        arr[start] = 1;
        ls.push_back(start);
        for( auto neigh: adj[start]){
            if(!arr[neigh]){
                dfs(neigh,ls,adj,arr);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(n != m+1) return 0;
        vector<int> ad[n];
        for(auto itr:adj){
            ad[itr[0]].push_back(itr[1]);
            ad[itr[1]].push_back(itr[0]);
        }
        
        vector<int> ls;
        int arr[n] = {0};
        dfs(0,ls,ad,arr);
        for(int i = 0;i<n;i++){
            if(arr[i] == 0) return 0;
        }
        return 1;
    }
};
