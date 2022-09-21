/*	2016. Maximum Difference Between Increasing Elements
	Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j]
	(i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
	Return the maximum difference. If no such i and j exists, return -1.
	
		input: [5,2,6,4,4,3,1]
		output: 4
		
	time complexity: naive --> O(n^2)
					 better--> O(nlogn)
					 optimised--> O(n)	
*/

#include<bits/stdc++.h>
using namespace std;

//naive Approach:
/*int findMaxIdxDiff(vector<int> &arr,int n){
	int maxIdx=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=i && arr[j]>=arr[i])
				maxIdx=max(maxIdx,j-i);
		}
	}
	return maxIdx;
} */

//better Approach: 
/*bool compare(pair<int,int>p1, pair<int,int> p2){
	if(p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
int findMaxIdxDiff(vector<int> &arr,int n){
	vector<pair<int,int> >vec;
	for(int i=0;i<n;i++)
		vec.push_back({arr[i],i});
	sort(vec.begin(),vec.end(),compare);
	int ans=INT_MIN,suffMaxIdx=vec[n-1].second;
	for(int i=n-2;i>=0;i--){
		ans=max(ans,suffMaxIdx-vec[i].second);
		suffMaxIdx=max(suffMaxIdx,vec[i].second);
	}
	return ans;	
}*/

//optimised Approach:
int findMaxIdxDiff(vector<int> &arr, int n)
{
    int leftMin[n] ;
    leftMin[0] = arr[0];
    for(int i = 1 ; i<n; i++)
        leftMin[i] = min(leftMin[i-1], arr[i]);
  
  
    //leftMin[i] = min{ arr[0...i] }
  
  
    int maxDist = INT_MIN;
    int i = n-1, j = n-1;
  
    while(i>=0  &&  j>=0)
    {
        if(arr[j] >= leftMin[i])
        {
            maxDist = max(maxDist, j-i);
            i--;
        }
        else 
            j--;
    }
  
    return maxDist;
  
          
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int ans=findMaxIdxDiff(arr,n);
	cout<<ans;
}
