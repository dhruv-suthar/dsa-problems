/*
Terms Of AP


Ayush is given a number ‘X’. He has been told that he has to find the first ‘X’ terms of the series 3 * ‘N’ + 2, which are not multiples of 4. Help Ayush to find it as he has not been able to answer.

Example: Given an ‘X’ = 4. The output array/list which must be passed to Ayush will be [ 5, 11, 14, 17 ].

*/

class Solution
{
       public:
      vector < int > termsOfAP(int x) {
	    // Write your code here.

	    vector<int> result;
	    int N=1;
	    for(int i=x;i>0;)
	    {
		int val = 3*(N);
		if((val+2)%4!=0)
		{
		    result.push_back(val+2);
		    i--;
		}
		N++;
	    } 

	    return result;
	}
};
