/*
Check if Possible to survive


Problem statement
You are a poor citizen of an island that has only one shop for groceries, which is open six days a week and is closed on Sundays. The first day of the week is Monday. You can buy ‘n’ units of food from a day’s work. Now each day, you need ‘x’ units of food to survive. You are making a boat to escape the island, which will require ‘d’ days to be made. You need to survive at least ‘d’ days on the island. You are given three integers n, x, and d. Your task is to determine if you can escape the island

'n': The number of units of food the person can buy from a day's work.
'x': The number of units of food needed daily for survival.
'd': The number of days required to build a boat.
To Find:
Determine if the person can gather enough food during the boat construction period ('d' days) to survive and successfully escape the island.

*/

class Solution
{
       public:
      bool isPossibleSurvive(int n,x,d) {
	    // Write your code here.
	    if(x> n) return false;
	    int available = (d- (d/7))  * n;
	    int req = d*x;
	    
	    if(available >= req)
	    {
 	      return true;
	    }
	    else
	    {
	      return false;
	    }
	}
};
