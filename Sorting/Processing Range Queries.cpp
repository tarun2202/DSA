/*  Processing Range Queries
	given an array initialised with all zeros. After Q queries, what will be the final state of the given 
	array.
	query: in every query given a range (i,j)- add 1 to all previous state of elements in the array.
	
		input: nums=[0 0 0 0 0 0] , q={(1,3), (3,4), (1,4), (0,5), (2,3)}
		output: [1 3 4 5 3 1]
	
	naive Approach: time complexity--> O(q.n)
					space complexity-->O(1)				
	optimised Approach: time complexity--> O(q+n)
						space complexity-->O(n)
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach:
/*vector<int> processQuery(vector<int>&nums, vector<pair<int,int> >&query, int q){
	for(int i=0;i<q;i++){
		for(int j=query[i].first; j<=query[i].second; j++){
			nums[j]= nums[j]+1;
		}
	}
	return nums;
}*/

//optimised approach:
vector<int> processQuery(vector<int>&nums, vector<pair<int,int> >&query, int q){
	int n=nums.size();
	for(int i=0;i<q;i++){
		nums[query[i].second]++;
		if(query[i].first > 0)
			nums[query[i].first-1]--;
	}
	vector<int>suffixSum(n);
	suffixSum[n-1]=nums[n-1];
	for(int i=n-2;i>=0;i--)
		suffixSum[i] = nums[i]+suffixSum[i+1];	
	return suffixSum;	
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n,0);
	int q;
	cin>>q;
	vector<pair<int,int> > query(q);
	for(int i=0;i<q;i++){
		cin>>query[i].first>>query[i].second;
		query.push_back({query[i].first,query[i].second});
	}
	nums= processQuery(nums,query,q);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";
}		
		  
