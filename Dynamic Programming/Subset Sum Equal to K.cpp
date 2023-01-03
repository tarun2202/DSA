/*	Subset Sum Equal to K 
	Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum 
	equal to given sum. 
		Input: arr[] = {3, 34, 4, 12, 5, 2}  sum = 9
		Output: 1 
		Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
*/

class Solution{   
public:
	
    //Memorization--> TC: O(sum*N)    SC: O(sum*N)
    /*bool findIsSubset(int i, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(sum==0)  return true;
        if(i==0)    return (arr[i]==sum);
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        bool notTaken=findIsSubset(i-1, sum, arr, dp);
        bool taken=false;
        
        if(sum>=arr[i])
            taken=findIsSubset(i-1, sum-arr[i], arr, dp);
        return dp[i][sum]=taken or notTaken;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return findIsSubset(n-1, sum, arr, dp);
    }*/
    
    
    //Tabulation--> TC: O(sum*N)    SC: O(sum*N)
    /*bool isSubsetSum(vector<int>arr, int k){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0; i<n; i++)
            dp[i][0]=true;
        if(arr[0]<=k)
            dp[0][arr[0]]=true;
        for(int idx=1;idx<n;idx++){
            for(int target=1; target<=k; target++){
                bool notTaken=dp[idx-1][target];
                bool taken=false;
                if(arr[idx]<=target)
                    taken=dp[idx-1][target-arr[idx]];
                dp[idx][target]=notTaken || taken;    
            }
        }
        return dp[n-1][k];
    }*/
    
    
    //Space Optimization--> TC: O(sum*N)    SC: O(sum)
    bool isSubsetSum(vector<int>arr, int k){
        int n=arr.size();
        vector<bool>prev(k+1,false);
        prev[0]=true;
        if(arr[0]<=k)
            prev[arr[0]]=true;
        for(int idx=1;idx<n;idx++){
            vector<bool>curr(k+1, false);
            curr[0]=true;
            for(int target=1; target<=k; target++){
                bool notTaken=prev[target];
                bool taken=false;
                if(arr[idx]<=target)
                    taken=prev[target-arr[idx]];
                curr[target]=notTaken || taken;    
            }
            prev=curr;
        }
        return prev[k];
    }
};
