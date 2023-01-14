/*	1043. Partition Array for Maximum Sum
	Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, 
	each subarray has their values changed to become the maximum value of that subarray.
	Return the largest sum of the given array after partitioning.
		Input: arr = [1,15,7,9,2,5,10], k = 3
		Output: 84
		Explanation: arr becomes [15,15,15,9,10,10,10]
*/

class Solution {
public:
    //Memorization --> TC: O(N.k)   SC: O(N)
    /*int f(int i, int k, int n, vector<int>& arr, vector<int> &dp){
        if(i == arr.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];    

        int len = 0;    
        int maxAns = INT_MIN;    
        int maxEle =INT_MIN;    
        for(int j=i; j < min(n, i+k); j++){
            len++;
            maxEle= max(maxEle, arr[j]);
            int sum = len*maxEle + f(j+1, k, n, arr, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;    
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, n, arr, dp);
    }*/

    //Tabulation --> TC: O(N^2)     SC: O(N)
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int len = 0;    
            int maxAns = INT_MIN;    
            int maxEle = INT_MIN;    
            for(int j=i; j < min(n, i+k); j++){
                len++;
                maxEle= max(maxEle, arr[j]);
                int sum = len*maxEle + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0]; 
    }
};
