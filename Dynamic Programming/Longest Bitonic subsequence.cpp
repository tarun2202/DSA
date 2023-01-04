/*	Longest Bitonic subsequence
	Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
	A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
		Input: nums = [1, 2, 5, 3, 2]
		Output: 5
		Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get length 5.
	
	time complexity: O(n^2)
	space complexity: O(n)
*/

class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr) {
	    int n=arr.size();
	    vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                if(arr[prev_index]<arr[i])
                    dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
        // reverse the direction of nested loops
        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index >i; prev_index --){
                if(arr[prev_index]<arr[i])
                    dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        return maxi;
	}
};
