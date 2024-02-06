/*
Find Minimum in Rotated Sorted Array


Problem statement
You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.

The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].

Your task is to find the minimum number in this array.

*/

class Solution
{
     public:
    int findMin(vector<int>& arr)
{
	// Write your code here.

	//iterate through arr till following condition satisfied
	 // current element > previous element
	// when condition break : return that element by arr[i]

	// for(int i=1;i<arr.size();i++){
	// 	if(arr[i] < arr[i-1]){
	// 		return arr[i];
	// 	}
	// }
	
	//return arr[0];

	int low = 0;
	int high = arr.size() - 1;
	int ans = INT_MAX;
	int mid = 0;
	while(low <= high){
		mid = (low + high) / 2;

		if(arr[low] <= arr[mid]){
			//if left part is sorted then definitely
			// low element wll always smallest in left part
			ans = min(ans,arr[low]);
			low = mid + 1;
		}
		else
		{
			//if right part is sorted then definitely
			// mid element wll always smallest in right part
			ans = min(ans,arr[mid]);
			high = mid - 1;
		}
	}

	return ans;
   }
};
