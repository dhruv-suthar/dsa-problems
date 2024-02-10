/*
Number of paths in a matrix with k coins


Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

Example 1:

Input:
k = 12, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [3, 2, 1]]
Output: 
2
Explanation: 
There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).

Example 2:

Input:
k = 16, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [9, 8, 7]]
Output: 
0 
Explanation: 
There are no possible paths that lead to sum=16
*/

class Solution
{
    public:    
    // long long totalNoOfPaths = 0;
    // long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
    //     // Code Here
    //     totalNoOfPaths = 0;
        
        
    //     explore(0,0,arr, k);
        
    //     return totalNoOfPaths;
    // }
    
    // void explore(int i, int j, vector<vector<int>> &arr, int k)
    // {
    //     int n = arr.size();
    //     if(k<0) return;
        
    //     if(i>=0 && i<n && j >=0 && j<n)
    //     {
            
    //         if(i==n-1 && j==n-1 && k==arr[i][j]) totalNoOfPaths+=1;
            
            
    //         explore(i+1,j,arr, k-arr[i][j]);
    //         explore(i,j+1,arr, k-arr[i][j]);
    //     }
    // }
    
        int dfs(vector<vector<int>> &arr, int n, int i, int j, int k, vector<vector<vector<int>>>& mp) {
        if(k <= 0)
            return 0;
        // check if valid index, only 2 dirs
        if(i >=n || j >=n)
            return 0;
        
        if(i == n-1 && j == n-1) {
            // used up exactly k coins, note : i,j must be valid and rightmost corner
            if(k == arr[i][j])  {
                return 1;
            }
            return 0;
        }
        if(mp[i][j][k]!=-1)
            return mp[i][j][k];
        
        // valid block explore neighbors
        mp[i][j][k] = dfs(arr, n, i+1, j, k-arr[i][j], mp) + dfs(arr, n, i, j+1, k-arr[i][j], mp);
        return mp[i][j][k];
   
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        // problem sets starting point as (0,0), no need worry about that.
        vector<vector<vector<int>>> mp(n, (vector<vector<int>> (n, (vector<int> (k+1, -1)))));
        return dfs(arr, n, 0, 0, k, mp);
    }
};
