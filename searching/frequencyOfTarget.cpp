/*	Find Frequency
	Given an array of integers,nums sorted in ascending order, and a target value. Print the number of 
	occurrences of the target in the given array.
	
	Input: 5				Output: 1
		   1 2 2 4 5				2
		   5						0
           1						1
           2						1
           3
           4
           5
	time complexity: O(log2n)
	space complexity: O(1)
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
		if(ans[0]==-1 and ans[1]==-1)
			cout<<0<<endl;
        else
            cout<<ans[1]-ans[0]+1<<endl;    	
	}	
}



