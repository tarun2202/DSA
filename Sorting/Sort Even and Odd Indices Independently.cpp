/*	2164. Sort Even and Odd Indices Independently
	You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
	-> Sort the values at odd indices of nums in non-increasing order.
	-> Sort the values at even indices of nums in non-decreasing order.
	Return the array formed after rearranging the values of nums.
	
		Input: nums = [4,1,2,3]
		Output: [2,3,4,1]
		
	time complexity: O(nlogn)
	space complexity: O(n)

*/
#include<bits/stdc++.h>
using namespace std;
void sortEvenOdd(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int i,j=0,k=odd.size()-1;
        for(i=0;i<nums.size();i++){
            if(i%2!=0)
                nums[i]=odd[k--];
            else
                nums[i]=even[j++];
        }
        //return nums;
    }
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	sortEvenOdd(nums);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";
}    
