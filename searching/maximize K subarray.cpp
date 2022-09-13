/*	Maximum subarray size, such that all subarrays of that size have sum less than k
	Given an array of n positive integers and a positive integer k, the task is to find the maximum 
	subarray size such that all subarrays of that size have the sum of elements less than or equals to k.
	
		Input : arr[] = {1, 2, 3, 4} and k = 8.
		Output : 2
		Sum of subarrays of size 1: 1, 2, 3, 4.
		Sum of subarrays of size 2: 3, 5, 7.
		Sum of subarrays of size 3: 6, 9.
		Sum of subarrays of size 4: 10.
	So, maximum subarray size such that all subarrays of that size have the sum of elements less than 8 is 2.
		
		Input : arr[] = {1, 2, 10, 4} and k = 8.
		Output : -1
		There is an array element with value greater than k, so subarray sum cannot be less than k.
--------------------------------------------------------------------------------------------------------------
	Naive approach: TC:O(N^2)		SC:O(1)
	Find all the subarrays and check if it follows the constraint or not and return the value of k for which,
	the sum is less than equal to target.
	
	Better Approach: using binary search + sliding window --> TC: O(nlogn)	SC: O(1)
	first find the sum of 1st window and then keep sliding the window by 1 till reaches end and check if 
	all the subarrays of size mid having sum<=x return true, and if any of the subarrays of size mid whose 
	sum>X return false
	
	Optimised Approach: TC:O(n)		SC:O(1)
	using the concet of sliding window alone.
*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach:
/*
int maxPossibleSubarraySize(vector<int>&arr,int n,int x){
		
}
*/

//Better Approach
/*
bool isPossible(vector<int>&arr,int mid,int X){	
	//isPossible function- inspect if all the subarrays of size mid hold condition (sum<=X)
	int n=arr.size();
	//when my answer is: (K)max=n i.e, arr=[1,2,3,4] ,X=50 then in this case max window size of array will
	// be the length of array itself.
	if(mid==n+1)	//edge case
		return false;
	int sum=0;	
	for(int i=0;i<mid;i++)	//takes O(mid)
		sum+=arr[i];
	if(sum>X)
		return false;
	int s=0,e=mid-1;
	while(e<n){			//takes O(n-mid)
		sum-=arr[s];
		s++; e++;
		sum+=arr[e];
		if(sum>X)	
			return false;
	}
	return true;
	//overall complexity of isPossible function is O(n)=O(mid)+O(n-mid)
}
int maxPossibleSubarraySize(vector<int>&arr,int n,int x){
	int left=0,right=n,mid;
	while(left<=right){
		mid =(left+right)/2;
		if(!isPossible(arr,mid,x))
			right=mid-1;
		else{
			//i'm at my answer- now check for mid+1, if returns true, then mid is my answer
			if(!isPossible(arr,mid+1,x))
				return mid;
			//my answer lies at right side 
			else
				left=mid+1;	
		}	
	}
	return 0; //if for no value of k, subarray sum is <=X
}*/

//Optimised Approach:
int maxPossibleSubarraySize(vector<int>&arr,int n,int X){
	int ans = n,sum = 0,start = 0;
	for (int end = 0; end < n; end++){
  		// Sliding window from left
  		sum += arr[end];
  		while (sum > X) {
   			// Sliding window from right
   			sum -= arr[start];
   			start++;
   			// Storing sub-array size - 1
   			// for which sum was greater than k
   			ans = min(ans, end - start + 1);
   			// Sum will be 0 if start>end
   			// because all elements are positive
   			// start>end only when arr[end]>k i.e,
   			// there is an array element with
   			// value greater than k, so sub-array
   			// sum cannot be less than k.
   			if (sum == 0)
    			break;
  		}
  		if (sum == 0) {
   			ans = -1;
   			break;
  		}
 	}
	return ans;
}
 
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int target;
	cin>>target;
	int maxK=maxPossibleSubarraySize(arr,n,target);
	cout<<maxK;	
}
