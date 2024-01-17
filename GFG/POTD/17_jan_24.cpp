/*
All Unique Permutations of an array

Given two integers m and n, try making a special sequence of numbers seq of length n such that

Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.	
*/

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> ans;
        permute(ans,n,0,arr);
        vector<vector<int>> nums(ans.begin(),ans.end());
        return nums;
    }
    void permute(set<vector<int>> &ans,int n,int index,vector<int> &str){
        if(index == n){
            ans.insert(str);
            return;
        }
        for(int i =index;i < n;i++){
            swap(str[index],str[i]);
            permute(ans,n,index +1,str);
            swap(str[index],str[i]);
        }
    }
};
