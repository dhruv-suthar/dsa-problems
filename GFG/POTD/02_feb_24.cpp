/*
Implement Atoi

Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.

Example 1:

Input:
s = "-123"
Output: 
-123
Explanation:
It is possible to convert -123 into an integer 
and is so returned in the form of an integer
Example 2:

Input:
s = "21a"
Output: 
-1
Explanation: 
The output is -1 as, due to the inclusion of 'a',
the given string cannot be converted to an integer.
*/

class Solution {
    int atoi(string s) {
        //Your code here
        
        
        int i = 0;
        int havingSign = 1;
        int result = 0;
        if(s[0] == '-'){
            havingSign = -1;
            i =1;
            
        }
        while (i < s.length()) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '-')
            {
                return -1;
            }
            result = result * 10 + (s[i] - '0');
            i++;
        }
        
        return result * havingSign;
    }

};
