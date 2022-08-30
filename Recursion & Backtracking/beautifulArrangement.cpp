/*	526. Beautiful Arrangement
	Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) 
	is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
		perm[i] is divisible by i.
		i is divisible by perm[i].
	Given an integer n, return the number of the beautiful arrangements that you can construct.
	Input: n = 3  i.e., nums={1,2,3}
	Output: 3
	Explanation: [123,213,321]
*/

#include<bits/stdc++.h>
using namespace std;
void check(vector<int>& nums,int& count,int i){
	if(i==nums.size()+1){
			count++;
			return;
	}
	for(int j=i;j<=nums.size();j++){
		if(nums[j-1]%i==0 || i%nums[j-1]==0){
			swap(nums[i-1],nums[j-1]);
			check(nums,count,i+1);
			swap(nums[i-1],nums[j-1]);	
		}		
	}	
}
int main(){
	int n;
	cin>>n;
    int count=0;
	vector<int> nums;
	for(int i=1;i<=n;i++)
		nums.push_back(i);
	check(nums,count,1);	
	cout<<count;
}
