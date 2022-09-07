/* Pair Sum Sorted
	Given a 1-indexed array of integers nums that is already sorted in non-decreasing order, find two 
	numbers such that they add up to a specific target number. 
	input: 4
		   2 7 11 15
		   9
	output:1 2
	
	time complexity: O(n) -Two pointer approach
	space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<int> pairSumIdx(vector<int> &arr,int target){
	vector<int>ans; //initializing with -1, in case idx not exist, return -1
	int n=arr.size();
	int start=0;
	int end=n-1;
	while(start<end){
		if(arr[start]+arr[end]==target){
			ans.push_back(start);
			ans.push_back(end);
			start++;
			end--;
		}
		else if((arr[start]+arr[end])<target)
			start++;
		else
			end--;		
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int target;
	cin>>target;
	ans=pairSumIdx(arr,target);
	if(ans.empty()) //when the target not found in array, return -1.
		cout<<-1;
	else{
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";	
	}
}
