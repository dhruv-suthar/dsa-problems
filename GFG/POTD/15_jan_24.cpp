/*
Grinding Geek
GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.

Note: On any day, Geek can only buy the new course that was made available for purchase that day.

Example 1:

Input:
n = 2
total = 10
cost = [10, 9]
Output: 2
Explanation: 
Geek can buy the first course for 10 amount, 
complete it on the same date and redeem 9 back. 
Next, he can buy and complete the 2nd course too.
*/
int max_courses(int n, int total, vector<int> &cost)
{
    //Code Here
    
//Code Here
    vector<int> curr(total + 1);
    for(int ind = n - 1; ind >= 0; ind--){
        for(int tot = total; tot >= 0; tot--){
            if(tot >= cost[ind])
                curr[tot] = max(curr[tot], 1 + curr[tot - 0.1 * cost[ind]]);
        }
    }
    return curr[total];
}