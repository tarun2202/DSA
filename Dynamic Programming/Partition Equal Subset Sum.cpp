/*	Partition Equal Subset Sum
	Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in 
	both parts is the same.
		Input: N = 4	arr = {1, 5, 11, 5}
		Output: YES
		Explanation: The two parts are {1, 5, 5} and {11}.
	
	Time Complexity: O(N*sum of elements/2)
	Auxiliary Space: O(N*sum of elements/2)	
*/

class Solution{
public:
    bool isPartitionPossible(int i, int target, int arr[], vector<vector<int>>&dp){
        if(target==0)
            return true;
        if(i==0)
            return (arr[i]==target);
        if(dp[i][target]!=-1)
            return dp[i][target];
        bool notTaken=isPartitionPossible(i-1, target, arr, dp);
        bool taken=false;
        if(target>=arr[i])
            taken=isPartitionPossible(i-1, target-arr[i], arr, dp);
        return dp[i][target] = taken || notTaken;    
    } 
    int equalPartition(int n, int arr[]){
        int totSum=0;
        for(int i=0;i<n;i++)
            totSum += arr[i];
        if(totSum%2!=0)
            return false;
        int target=totSum/2;
        vector<vector<int>>dp (n, vector<int>(target+1, -1));
        return isPartitionPossible(n-1, target, arr, dp);
    }
};
