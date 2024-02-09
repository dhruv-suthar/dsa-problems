/*
Check for Children Sum Property in a Binary Tree


Binary tree question

For every node check whether it there child nodes sum equal to parent node. For leaf node (for those who don't have any children) consider 0 as sum 

Example 1:

Input:
Binary tree
       35
      /   \
     20    15
    /  \   /  \
   15  5  10   5
Output: 
1
Explanation: 
Here, every node is sum of its left and right child.

Example 2:

Input:
Tree:
    10
   /  \
 5   5
 /  \
 10   15
Output:
0
Explanation:
Here, 5 child left and right node sum not equal to 5.
*/

class Solution
{
    public:
   int isSumProperty(Node *root)
    {
     // Add your code here
     queue<Node*> nodeQ;
     nodeQ.push(root);
     
     while(!nodeQ.empty())
     {
         Node* frontEle = nodeQ.front();
         nodeQ.pop();
         
         int leftEle = 0, rightEle = 0;
         
         if(frontEle->left)
         {
             leftEle = frontEle->left->data;
             nodeQ.push(frontEle->left);
         }
         
        if(frontEle->right)
         {
             rightEle = frontEle->right->data;
             nodeQ.push(frontEle->right);
         }
         
         
         if((leftEle+rightEle != frontEle->data) && (frontEle->left || frontEle->right))
         {
             return 0;
         }
     }
     
     return 1;
     
    }
};
