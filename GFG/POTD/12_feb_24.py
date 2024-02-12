/*
Recursive sequence


A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

Note: As the answer can be very large, return the answer modulo 109+7.


Example 1:

Input: n = 5
Output: 365527
Explanation: 
F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.

Example 2:

Input: n = 7
Output: 6006997207
Explanation: 
F(7) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 + 
16*17*18*19*20*21 + 22*23*24*25*26*27*28 = 6006997207.
6006997207 % 109+7 = 6997165
*/

class Solution:
    def sequence(self, n):
        currentVal = 1
        product = 0
        mod_value = 10**9 + 7
        for i in range(1,n+1):
            currentProduct = 1
            for ele in range(currentVal,currentVal+i):
                currentProduct = (currentProduct * ele)%mod_value
            product = (product+currentProduct)%mod_value 
            currentVal+=i
        
        return product
