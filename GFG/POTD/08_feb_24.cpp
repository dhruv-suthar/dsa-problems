/*
Check if all leaves are at same leve


Binary tree question

Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.

Example 2:

Input:
Tree:
    10
   /  \
 20   30
 /  \
 10   15
Output:
false
Explanation:
The binary tree has a height of 3 and the leaves are not at the same level.
*/

class Solution
{
    public:
   int fun(Node*root,int level,int &leafl)
    {
        if(root==NULL)
        return 1;
        if(root->left==NULL && root->right==NULL)  
        { 
            if(leafl==0) 
            {
            leafl=level;  
            return 1;
            }
            
            if(level!=leafl)
            return 0;
        } 
        int lh=fun(root->left,level+1,leafl);
        int rh=fun(root->right,level+1,leafl); 
        if(lh==1 &&rh==1)
        return 1; 
        
        return 0;
    }
    bool check(Node *root)
    { 
        int leafl=0,level=0;
        return fun(root,level,leafl);
    }
};
