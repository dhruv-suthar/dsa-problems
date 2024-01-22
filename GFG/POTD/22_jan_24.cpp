/*
Paths from root with a specified sum


Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path not necessarily end on a leaf node.


Example 1:

Input : 
sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15   
        /  \     /  \
       6    7   8    9      

Output :
1 3 4
Explanation : 
Sum of path 1, 3, 4 = 8.
*/

class Solution
{
    public:
    void dfs(Node *root, int sum, int currSum,vector<int> &temp,vector<vector<int>> &ans)
    {
        
        if(root == NULL) return;
        
        currSum += root->key;
        temp.push_back(root->key);
        if(currSum == sum){
            ans.push_back(temp);
        }
        dfs(root->left,sum,currSum,temp,ans);
        
        dfs(root->right,sum,currSum,temp,ans);
        
        temp.erase(temp.end()-1);
        
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<int> temp;
        vector<vector<int>> ans;
        
        dfs(root,sum,0,temp,ans);
        
        return ans;
    }
};
