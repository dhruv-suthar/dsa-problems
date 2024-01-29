/*
Count digit groupings of a number




The problem involves dividing a string of digits into sub-groups. A valid grouping is achieved if the sum of digits in a sub-group is less than or equal to the sum of the digits in the immediately following sub-group. The task is to determine the total number of valid groupings for a given string. This can be solved using dynamic programming to consider all possible sub-group combinations.

Example 1: 

Input: 
str = "1119"
Output: 
7
Explanation: 
One valid grouping is {"1", "11", "9"}.
Sum of digits of first sub-group ("1") is 1,
for the second sub-group ("11"), it is 2,
and for the third one ("9"), it is 9.
As the sum of digits of the sub-groups is 
in increasing order, it forms a valid grouping.
Other valid grouping are {"1", "119"}, {"1","1","19"}, 
{"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
are six other valid groupings.
*/

class Solution
{
  	public:
	int solve(int ind, int sum, string &str, int n, vector<vector<int>>&dp){
	    if(ind==n) return 1;
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int ans=0, curr=0;
	    for(int i=ind;i<n;i++){
	        curr+=str[i]-'0';
	        if(curr>=sum){
	            ans+=solve(i+1, curr, str, n, dp);
	        }
	    }
	    return dp[ind][sum]=ans;
	}
	
	int TotalCount(string str){
	    // Code here
	    int n=str.length();
	    vector<vector<int>>dp(n+1, vector<int>(9*n+1,-1));
	    return solve(0, 0, str, n,dp);
	}
        
};
