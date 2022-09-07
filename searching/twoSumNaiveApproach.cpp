/* Pair Sum Sorted
	Given a 1-indexed array of integers nums that is already sorted in non-decreasing order, find two 
	numbers such that they add up to a specific target number. 
	input: 4
		   2 7 11 15
		   9
	output:1 2
	
	time complexity: O(n^2) --> naive approach- using two for loop
	space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<int> twoSumPair(vector<int> &arr, int n, int target){
	//int rem;
    for(int i=0;i<n;i++){
		//rem=target-arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==target){
				ans.push_back(i);
                ans.push_back(j);
				break;
			}
		}
	}
    return ans;
}
int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;
	ans=twoSumPair(nums, n, target);
    if(ans.empty())
        cout<<-1;
    else{
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }   
}
