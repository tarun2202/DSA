/*	456. 132 Pattern
	Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k]
	such that i < j < k and nums[i] < nums[k] < nums[j].
	Return true if there is a 132 pattern in nums, otherwise, return false.
		Input: nums = [3,1,4,2]
		Output: true
		Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
	
	naive approach-->	TC: O(n^3)	SC: O(1)
	better approach-->	TC: O(n^2)  SC: O(1)
	optimal approach-->	TC: O(n)	SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;
//naive approach
/*bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return false; 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]<nums[k] && nums[k]<nums[j])
                    return true;
            }
        }
    }
    return false;
}*/

//better approach
/*bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return false;
    int minm=nums[0];
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(nums[k] > minm && nums[j] > nums[k])
                return true;
            minm=min(minm,nums[j]);
        }
    }
    return false;
}*/

//optimised approach
bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return false;
    stack<int>st;
    int thirdElement=INT_MIN; //nums[k]
    for(int i=n-1;i>=0;i--){
        if(nums[i]<thirdElement)
            return true;
        while(!st.empty() && st.top()<nums[i]){
            thirdElement=st.top();
            st.pop();
        }    
        st.push(nums[i]);
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    bool ans=find132pattern(nums);
    cout<<ans;
}

