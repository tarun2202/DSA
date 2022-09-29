/*	485. Max Consecutive Ones
	Given a binary array nums, return the maximum number of consecutive 1's in the array.
		Input: nums = [1,1,0,1,1,1]
		Output: 3
		Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
	
	time complexity: O(n)
	space complexity:O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
int findConsecutiveOneLength(int arr[],int n){
	int count=0, maxm=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			count++;
			maxm=max(maxm,count);
		}
		else 
			count=0;
	}
	return maxm;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<findConsecutiveOneLength(arr,n);	
}
