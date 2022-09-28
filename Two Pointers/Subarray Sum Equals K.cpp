/*	Subarray with given sum
	Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which 
	adds to a given number S.
	In case of multiple subarrays, return the subarray which comes first on moving from left to right.
		Input: nums = [1,2,3], k = 3
		Output: 2
		
	naive approach--> TC: O(n^2)
	optimised app --> TC: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;

//optimised approach--> using 2 pointers
void findSubarray(vector<int> &nums,int n,int sum){
	long long currSum=nums[0], count=0;
	long long i=0,j=0;
	while(j<n){
		if(currSum<sum){
			j++;
			if(j<n)	currSum+=nums[j]; 
		}
		else if(currSum>sum){
			currSum-=nums[i];
			i++;
			if(i>j){
				j=i;
				if(j<n) currSum+=nums[j];
			} 
		}
		else{
			cout<<i<<" "<<j;
			break;
		}	
	}
}

//naive approach
/*void findSubarray(vector<int> &nums,int n,int sum){
	long long currSum, count=0;
    for(int i=0;i<n;i++){
        currSum=0;
        for(int j=i;j<n;j++){
            currSum += nums[j];
            if(currSum==sum)
                count++;
        }
    }
	cout<<count;	
}*/

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int sum;
	cin>>sum;	
	findSubarray(nums,n,sum);	
}
