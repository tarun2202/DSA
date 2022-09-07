/* Pair Sum Sorted
	Given a 1-indexed array of integers nums that is already sorted in non-decreasing order, find two 
	numbers such that they add up to a specific target number. 
	input: 4
		   2 7 11 15
		   9
	output:0 1
	
	time complexity: O(nlogn)	--> Better Approach-using binary search
	space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> nums, int n, int target, int j){
	int low=j;
	int high=n-1;
	while(low<=high){
	int mid=(low+high)/2;
	if(nums[mid]==target)
		return mid;
	else if(nums[mid]>target)
		high=mid-1;
	else
		low=mid+1;
	}
	return -1;
}
int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;	
	int index1, index2;
	for(int i=0;i<n;i++){
		index1=i;
		int temp=binarySearch(nums, n, target-nums[i], i+1);
		if(temp!=-1) {
			index2=temp;
			cout<<index1<<" "<<index2<<endl; 
			break;
		}
		else 
			continue;
	}
	return 0;
}
