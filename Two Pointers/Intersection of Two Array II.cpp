/*	350. Intersection of Two Arrays II
	Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result 
	must appear as many times as it shows in both arrays and you may return the result in any order.
		Input: nums1 = [1,2,2,1], nums2 = [2,2]
		Output: [2,2]
		
	time complexity: O(max(m,n))
	space complexity: O(max(m,n))	
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> findIntersection(int a[], int m,  int b[], int n) {
    sort(a,a+m);
    sort(b,b+n);
	vector<int>ans;
	int i=0,j=0;
	while(i<m && j<n){
		if(a[i]<b[j])
			i++;
		else if(a[i]>b[j])
			j++;
		else{
			ans.push_back(a[i]);
			i++; j++;
		}		
	}	
	return ans;
}

int main(){
	int m,n;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++)
		cin>>a[i];
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	vector<int>ans = findIntersection(a,m,b,n);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}
