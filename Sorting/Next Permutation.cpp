/*	31. Next Greater Permutation
	Given an array having N elements, find the nect lexicographical permutation ofthe given array. 
	Note: if no next greater permuation exist: return the array in ascending order.
		
		input: arr=[1 2 3]
		output: [1 3 2]
		
	naive Approach-
		time complexity: O(n.n!)
		space complexity: O(n)	
	optimised Approach-	
		time complexity: O(n)
		space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int k, l;
    for (k = n - 2; k >= 0; k--) {
        if (nums[k] < nums[k + 1])
            break;
    }
    if (k < 0)   //my array is already at its highest lexicographical order : whole array in                             descending order
        reverse(nums.begin(), nums.end());
    else {
        for (l = n - 1; l > k; l--) {
            if (nums[l] > nums[k]) 
                break;
        } 
        swap(nums[k], nums[l]);
        //reverse(nums.begin() + k + 1, nums.end());
		int start=k+1, end=n-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    for(int i=0;i<n;i++)
    	cout<<nums[i]<<" ";	
}
