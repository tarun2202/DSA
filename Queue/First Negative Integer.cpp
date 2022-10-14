/*	First negative integer in every window of size k
	Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window
	(contiguous subarray) of size K.
		Input : N = 5, A[] = {-8, 2, 3, -6, 10}  K = 2
		Output : [ -8 0 -6 -6 ]
	
	naive approach    --> TC: O(k(n-k+1))	SC: O(1) 
	optimised approach--> TC: O(n)			SC: O(k)	
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
/*int findNegative(int i, int j, vector<int>&nums){
	for(int k=i;k<=j;k++){
		if(nums[k]<0){
			return nums[k];
		}
	}
	return 0;
}
vector<int> findFirstNegative(vector<int> &nums, int k){
	vector<int>ans;
	for(int i=0;i<nums.size()-k+1;i++)
		ans.push_back(findNegative(i,i+k-1,nums));
	return ans;	
}*/

// optimised approach
vector<int> findFirstNegative(vector<int> &nums, int k){
	queue<int>q;
    vector<int>ans;
    for(int i=0;i<k;i++)
        if(A[i]<0)
            q.push(i);
    for(int i=k;i<n;i++){
        q.empty() ? ans.push_back(0):ans.push_back(A[q.front()]);
        if(!q.empty() && q.front()==i-k)
            q.pop();
        if(A[i]<0)
            q.push(i);
    }
    q.empty()? ans.push_back(0): ans.push_back(A[q.front()]);
    return ans;	
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int k;
	cin>>k;	
	vector<int> ans= findFirstNegative(nums,k);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";	
}
