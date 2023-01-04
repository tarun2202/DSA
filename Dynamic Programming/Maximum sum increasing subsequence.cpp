/*	Maximum sum increasing subsequence
	Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the 
	integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 
		Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
		Output: 106 
		Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}
	
	time complexity: O(n^2)
	space complexity: O(n)	
*/

class Solution{
public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>msis(n);
	    for(int i=0; i<n; i++)
	        msis[i]=arr[i];
	    for(int i=1;i<n;i++)
	        for(int j=0;j<i;j++)
	            if(arr[i] > arr[j] and msis[i] < msis[j]+arr[i])
	                msis[i]=msis[j]+arr[i];
	  
	    int maxm=0;
	    for(int i=0;i<n;i++)
	        if(maxm < msis[i])
	            maxm=max(maxm, msis[i]);
	    return maxm;         
	}  
};
