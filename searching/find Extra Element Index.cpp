/*	Index of Extra Element
	Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. 
	First array has one element extra added in between. Find the index of the extra element.
		
		input: 7
			   2 4 6 8 9 10 12
			   2 4 6 8 10 12
		output: 4 i.e., the index of extra element 9 in arr1.
		
	time complexity:O(logn)
	space complexity: O(1)	   
*/

#include<bits/stdc++.h>
using namespace std;

//native approach --> iterate over the whole array
/*int findExtraElementIndex(vector<int>&arr1,vector<int>&arr2,int n){	
	int index=-1;
	for(int i=0;i<n;i++){
		if(arr1[i]!=arr2[i]){
			index=i;
			break;
		}
	}
	return index;
}
*/

//optimised approach --> using binary search
int findExtraElementIndex(vector<int>&arr1,vector<int>&arr2,int n){
	//int n=arr1.size();
	int left=0,right=n-1,mid;
	int index=-1;
	while(left<=right){
		mid=(left+right)/2;
		if(arr1[mid]==arr2[mid])
			left=mid+1;
		else{
			index=mid;
			right=mid-1;
		}
	}
	return index;
}
int main() {
    int n;
	cin>>n;
	vector<int>arr1(n);
	vector<int>arr2(n-1);
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<n-1;i++)
		cin>>arr2[i];
	int ans=findExtraElementIndex(arr1,arr2,n);
	cout<<ans;
}
