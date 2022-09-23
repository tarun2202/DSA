/*	493. Reverse Pairs
	Given an integer array nums, return the number of reverse pairs in the array.
	A reverse pair is a pair (i, j) where:
			0 <= i < j < nums.length and
			nums[i] > 2 * nums[j].
	
	Brute Force: TC: O(n^2)
				 SC: O(1)
	Optimised Approach: TC: O(nlogn)+O(n)+O(n) ~ O(nlogn)
						SC: O(n)			 
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach: using O(n^2)
/*int reversePairs(vector<int>& nums) {
    int n=nums.size();
	int count=0;
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if(nums[i]>2*nums[j])
                count++;
        }
    }
    return count;
}*/

long long ans;
void merge(vector<int> &nums,long long l,long long m,long long r){
    long long temp[r+1];
    long long k = l;
    long long s1 = l,s2=m+1,e1=m,e2=r,c=l;
    for(int j=s2;j<=e2;j++){
    	while(k<=e1 && nums[k]<=(long long)2*nums[j])
  		    k++;
        ans += (e1-k+1);
    }
    for(;s1<=e1&&s2<=e2;){
        if(nums[s1]<=nums[s2])
            temp[c++] = nums[s1++];
        else
            temp[c++] = nums[s2++];               
    }
    for( ;s1<=e1;)
        temp[c++] = nums[s1++];
    for( ;s2<=e2; )
        temp[c++] = nums[s2++];
    for(int i=l;i<=r;i++)
        nums[i] = temp[i];
}
void mergeSort(vector<int> &nums,long long l,long long r){
   	if(l==r)
       	return ;
   	long long m = l +(r-l)/2;
   	mergeSort(nums,l,m);
   	mergeSort(nums,m+1,r);
   	merge(nums,l,m,r);
}
int reversePairs(vector<int>& nums) {
   	ans = 0;
   	mergeSort(nums,0,nums.size()-1);
   	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	reversePairs(nums);
	cout<<ans;	
}
