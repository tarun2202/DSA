/*	454. 4Sum II
	Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l)
	such that:
		0 <= i, j, k, l < n
		nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
	
	Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
	Output: 2
	Explanation: The two tuples are-
				1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
				2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0	
				
	Naive Approach--> 		TC: O(n^4)   SC: O(1) 
	Optimised Approach--> 	TC: O(n^2)   SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach
int find4Sum(int arr1[], int arr2[], int arr3[], int arr4[], int n){
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				for(int l=0;l<n;l++){
					if(arr1[i]+arr2[j]+arr3[k]+arr4[l]==0)
						ans++;
				}
			}
		}
	}
	return ans;
}

//optimised Approach
/*int find4Sum(int arr1[], int arr2[], int arr3[], int arr4[], int n){
    unordered_map<int,int>m;
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[{arr1[i]+arr2[j]}]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans+=m[-(arr3[i]+arr4[j])];
    return ans;
}*/

int main(){
	int n;
	cin>>n;
	int arr1[n], arr2[n], arr3[n], arr4[n];
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<n;i++)
		cin>>arr2[i];
	for(int i=0;i<n;i++)
		cin>>arr3[i];
	for(int i=0;i<n;i++)
		cin>>arr4[i];
	cout<<find4Sum(arr1, arr2, arr3, arr4, n);			
}
