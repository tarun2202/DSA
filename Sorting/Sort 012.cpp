/*	GFG: Sort an array of 0s, 1s and 2s
	
	Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
		Input: arr[]= {0 2 1 2 0}
		Output: [0 0 1 2 2]
	
	time complexity: O(n)
	space complexity: O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
//using 2 pointers approach--> TC:O(2n) 
/*void sort012(vector<int>&nums, int n) {
	int i=0,j=n-1;
	while(i<=j){
		if(nums[i]==0)
			i++;
		else if(nums[j]!=0)
			j--;
		else
			swap(nums[i],nums[j]);		
	}
	//j is pointing to last zero in the nums[]
	//now arranement range is from (j to k): j=j+1, to k=n-1;
	j++; 
	int k=n-1;
	while(j<=k){
		if(nums[j]==1)
			j++;
		else if(nums[k]==2)
			k--;
		else
			swap(nums[j],nums[k]);		
	}
}*/

//using count sort--> TC: O(2n)
/*void sort012(vector<int>&nums, int n) {
	int count0=0, count1=0, count2=0;
	for(int i=0;i<n;i++){
		if(nums[i]==0)
			count0++;
		else if(nums[i]==1)
			count1++;
		else
			count2++;		
	}
	int i=0,j,k;
	while(i<count0)
		nums[i++]=0;
	j=0;
	while(j<count1){
		nums[j+count0]=1;
		j++;
	}
	k=0;	
	while(k<count2){
		nums[k+count1+count0]=2;
		k++;
	}		
}*/

//optimised approach--> using 3 pointers approach (dutch national flag algorithm) --> TC:O(n)  
void sort012(vector<int>&nums, int n) {
	int low=0, mid=0, high=n-1;
	while (mid <= high) { 
        switch (nums[mid]) { 
        // If the element is 0 
        	case 0: 
                swap(nums[low++], nums[mid++]); 
                break; 
            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 
            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[high--]); 
                break; 
        }
    }	
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	sort012(nums,n);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";	
}
