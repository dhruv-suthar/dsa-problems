/*
Sequence of Sequence
Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.

Example 1:

Input: 
m = 10
n = 4
Output: 
4
Explaination: 
There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.	
*/

class Solution{
public:
   int solve( int number, int m,int count)
      {
          
          if(count== 0)
          {
              return 1;
          }
          if(number> m)
          {
              return 0;
          }
          
          int take= solve(number*2,m,count-1);
          int nottake= solve( number+1,m,count);
          
          return (take+ nottake);
      }
    int numberSequence(int m, int n){
        // code here
        
        return solve(1,m,n);
    }
};
