/*	1004. Max Consecutive Ones III
	Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can 
	flip at most k 0's.
	
		Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
		Output: 6
		Explanation: [1,1,1,0,0,1,1,1,1,1,1]
		
	naive approach--> TC: O(n^2)		SC: O(1)	
	optimised approach--> TC: O(n)		SC: O(1)

	Optimised approach: 	
	1) Keep two pointers, l and r. Initially, both will be placed at index 0.
	2) Now, start with the r pointer.
	3) for every element of the array, check if the value at index r is 0. If it is, increment the zero counter. 
	   If at any given point of time, the zero counter is more then the given k, begin processing the l pointer.
	4) Keep incrementing the l pointer. If the value at l is 0,decrement the zero counter.
	5) Keep track of the max length by comparing the max with the diferrence between the r pointer and the l pointer. 
	   At the end return the max.
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
int countMaxOnes(int arr[],int n,int k){
	int zerocnt=0;
	int maxm=0;
	for(int i=0;i<n;i++){
		zerocnt=0;
		for(int j=i;j<n;j++){		
			if(arr[j]==0)
				zerocnt++;
			if(zerocnt<=k)
				maxm=max(maxm,j-i+1);			
		}
	}
	return maxm;
}

//optimised approach- using 2 pointers, sliding window
/*int countMaxOnes(int arr[],int n,int k){
	int zerocnt=0;
	int ans=0;
	int i=0,j=0;
	for(j=0;j<n;j++){
		if(arr[j]==0)
			zerocnt++;
		while(zerocnt>k){
			if(arr[i]==0)
				zerocnt--;
			i++;	
		}	
		ans=max(ans,j-i+1);
	}	
	return ans;
}*/

int main(){
	int n;	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;	cin>>k;
	int ans= countMaxOnes(arr,n,k);
	cout<<ans;	
}
