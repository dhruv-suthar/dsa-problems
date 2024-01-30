/*
LCS of three strings





Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: 
"geeks"is the longest common
subsequence with length 5.
*/

class Solution:

    def LCSof3(self,A,B,C,n1,n2,n3):
        len_A, len_B, len_C = n1, n2, n3

        # Initialize a 3D table to store the lengths of common subsequences
        dp = [[[0] * (len_C + 1) for _ in range(len_B + 1)] for _ in range(len_A + 1)]
    
        # Build the table using bottom-up dynamic programming
        for i in range(1, len_A + 1):
            for j in range(1, len_B + 1):
                for k in range(1, len_C + 1):
                    if A[i - 1] == B[j - 1] == C[k - 1]:
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
                    else:
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])
    
        return dp[len_A][len_B][len_C]
