/*	34. Find First and Last Position of Element in Sorted Array
	
	Given an array of integers nums sorted in non-decreasing order, find the starting and ending position 
	of a given target value.
	If target is not found in the array, return [-1, -1].
	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]
	
	time complexity: O(log2n)
*/

#include<bits/stdc++.h>	
using namespace std;
vector<int> ans;
vector<int> findOccurence(vector<int>& a, int target) {
	int s = 0, e = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == s || a[m] != a[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
		}
	}

	//last occurrence
	s = 0, e = a.size()-1;
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == e || a[m] != a[m+1]){
				ans[1] = m;
				break;
			}
			else{
				s = m+1;
				ans[1] = m+1;
			}
		}
	}
	return ans; 
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int t;
	cin>>t;
	while(t--){
		int target;
		cin>>target;
		ans=findOccurence(arr,target);
		for(auto i:ans)
			cout<<i<<" ";
        cout<<endl;    	
	}	
}

