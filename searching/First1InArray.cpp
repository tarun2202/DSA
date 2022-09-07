/*	First 1 in Array
	Given a sorted array consisting of 0's and 1's. The task is to print the index of first 1 in the given 
	array.
	input:  5
			0 0 0 1 1
	output: 4 //following 1 based indexing
	input: 3
		   0 0 0
	Output: -1
	
	time complexity: O(nlogn)
	space complexity:O(1)	   	 		
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int start=0;
	int end=n-1;
	int fo1=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(1>arr[mid])
			start = mid+1;
		else if(1<arr[mid])
			end=mid-1;
		else{
			if(mid==start || arr[mid]!=arr[mid-1]){
				fo1=mid;
				break;
			}
			else{
				end=mid-1;
				fo1=mid-1;
			}
		}		
	}
	cout<<fo1;	
}
