/*
Brackets in Matrix Chain Multiplication



Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.


Example 1:

Input: 
n = 5
p[] = {40, 20, 30, 10, 30}
Output: 
True
Explaination: 
Let's divide this into matrix(only 4 are possible) 
[ [40, 20] -> A
, [20, 30] -> B
, [30, 10] ->C
, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC)
then we multiply A to (BC) -> (A(BC))
then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
*/

class Solution
{
  private:
    vector<vector<int>> dp, val;
    int n;
public:
    int MCM(int i, int j, int arr[]){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int tmp = arr[i-1] * arr[k] * arr[j] + MCM(i, k, arr) + MCM(k+1, j, arr);
            if(tmp < ans) ans = tmp, val[i][j] = k; 
        }
        return dp[i][j] = ans;
    }
    void construct_string(int i, int j, string &ans){
        if(i > j) return; 
        if(i == j){
            ans.push_back('A' + i - 1);
            return;
        }
        ans.push_back('('); 
        construct_string(i, val[i][j], ans); 
        construct_string(val[i][j] + 1, j, ans);
        ans.push_back(')'); 
        return;
    }
    string matrixChainOrder(int p[], int N){ 
        n = N, dp.resize(n, vector<int>(n, -1)), val.resize(n, vector<int>(n, -1));
        MCM(1, n-1, p);
        string ans = ""; 
        construct_string(1, n-1, ans);  
        return ans;
    }
        
};
