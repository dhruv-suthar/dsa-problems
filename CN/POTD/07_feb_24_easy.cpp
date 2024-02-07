/*
Product of the Last K Numbers


Problem statement
Given a sequence of queries of insertion and getProduct, you need to create an array using queries of type-0 and answer queries of type-1.

In each query, the input is of two types :

0 X: insert element ‘X’ at the end array.

1 K: find the product of the last 'K' elements in the array

Note:

For the query of type 1, you can assume that the array has at least k values. And at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

Input:
1
12
0 24
1 1
0 58
0 2
1 3
0 73
1 3
0 66
0 0
1 4
0 8
1 7
Sample Output:
24 2784 8468 0 0

*/

class Solution
{
     public:
    vector<int> solve( int q, vector<pair<int, int>> queries ) 
{
	// Write your code here
	vector<int> tempArr;

	vector<int> ansArr;

	for(int i=0;i<q;i++){
		if(queries[i].first == 0){
			//insert element in arr
			tempArr.push_back(queries[i].second);
		}
		else
		{
			//do product of last queries[i].second elemenst from arr
			int ans = 1;
			int kCounter = queries[i].second;

			for(int j=tempArr.size()-1;kCounter>0;j--,kCounter--)
			{

				ans = ans * tempArr[j]; 
			}

			
			ansArr.push_back(ans);
		}
		
	}

	return ansArr;
}


};
