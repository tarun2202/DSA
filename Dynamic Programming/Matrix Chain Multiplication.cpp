/*	Matrix Chain Multiplication
	Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way 
	is the one that involves the least number of multiplications.
	The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where 
	the ith matrix has the dimensions (arr[i-1] x arr[i]).
		Input: N = 5	arr = {40, 20, 30, 10, 30}
		Output: 26000
	
	time complexity: O(n^3)
	space complexity: O(n^2)	
*/

class Solution{
public:
    //Recursion --> TC: O(exponential)  
    /*int minCost(int i, int j, vector<int> &arr){
        if(i == j)
            return 0;
        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            ans= min(ans, minCost(i, k, arr) + minCost(k+1, j, arr) + arr[i-1]*arr[k]*arr[j]);
        }
        return ans;
    }
    int matrixMultiplication(int n, int arr[]){
        return minCost(1, n-1, arr);    
    }*/
    
    //Memorization--> TC: O(N^3)    SC: O(N^2)
    /*int minCost(int i, int j, int arr[], vector<vector<int>> &dp){
        if(i == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        dp[i][j] = INT_MAX;
        for(int k=i; k<j; k++){
            int temp = minCost(i, k, arr, dp) + minCost(k+1, j, arr, dp) + arr[i-1]*arr[k]*arr[j];
            dp[i][j] = min(dp[i][j], temp);
        }
        return dp[i][j];
    }
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n, vector<int>(n, -1));    
        return minCost(1, n-1, arr, dp);    
    }*/
    
    //Tabulation--> TC: O(N^3)  SC: O(N^2)
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N,vector<int>(N,-1));
    
        for(int i=1; i<N; i++)
            dp[i][i] = 0;
    
    
        for(int i=N-1; i>=1; i--){
            for(int j=i+1; j<N; j++){
                dp[i][j] = INT_MAX;
    
                // partioning loop
                for(int k = i; k<= j-1; k++){
                    int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    dp[i][j] = min(dp[i][j], ans);
                }
            }
        }
        return dp[1][N-1];
    }
};
