/*	209. Minimum Size Subarray Sum
	Given an array of positive integers nums and a positive integer target, return the minimal length of 
	a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal 
	to target. If there is no such subarray, return 0 instead.
	
		Input: target = 7, nums = [2,3,1,2,4,3]
		Output: 2
		Explanation: The subarray [4,3] has the minimal length under the problem constraint.
		
	time complexity: Naive --> O(N^2)
					 Better--> O(nlogn)
					 Optimised--> O(n)	
	space complexity: O(1)						  	
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach:
/*int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j=i ; j<n ; j++) {
                sum += nums[j];
                if(sum >= target)
                    ans = min(ans, j-i+1);
            }
        }
        if(ans==INT_MAX)
        	return 0;
        else 
			return ans;
    }*/
    
//better approach:
/*int minSubArrayLen(int target, vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        if(nums[nums.size()-1]<target)
            return 0;
        if(nums[0]>target)
            return 1;
        int ans =INT_MAX;
        for(int i=0;i<nums.size();i++){
            int l = i;
            int h = nums.size()-1;
            while(l<=h){
                int mid = l+(h-l)/2;
                int psum;
                if(i!=0)
                    psum = nums[mid]-nums[i-1];
                else 
                    psum =nums[mid];
                if(psum>=target){
                    int psum1 = (i!=0)?nums[mid-1]-nums[i-1]:nums[mid-1];
                    if(mid!=0 && psum1<target){
                        ans = min(ans,mid-i+1);
                        break;
                    }
                    else
                        h = mid-1;
                }                 
                else
                    l = mid+1;
            }
        }
        return ans;
    }*/
	
//Optimised Approach:
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum=0;
    int left=0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        while(sum >= target) {
            ans = min(ans, i+1-left);
            sum -= nums[left];
            left++;
        }
    }
    return (ans==INT_MAX) ? 0:ans;
}	    
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;
	cout<<minSubArrayLen(target,nums);	
}
