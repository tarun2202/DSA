/*	Minimum Cost of ropes
	There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect 
	two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size 
	array arr[] contains the lengths of the ropes. 
		Input:n = 4		arr[] = {4, 3, 2, 6}
		Output: 29
		
	time complexity: 	
*/

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans=0;
        priority_queue<long long, vector<long long>, greater<long long>>pq(arr, arr+n);
        while(pq.size()>1){
            long long p=pq.top();
            pq.pop();
            long long q=pq.top();
            pq.pop();
            ans+=p+q;
            pq.push(p+q);
        }
        return ans;
    }
};
