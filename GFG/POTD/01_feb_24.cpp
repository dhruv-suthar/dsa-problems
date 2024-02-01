/*
Panagram Checking

Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1

Example 2:

Input:
s = "sdfs"
Output: 
0
Explanation: 
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
*/

class Solution:
    
    #Function to check if a string is Pangram or not.
    def checkPangram(self,s):
        l = "abcdefghijklmnopqrstuvwxyz"
        s = s.lower()
        
        for i in l:
            if i not in s:
                return False
        return True
