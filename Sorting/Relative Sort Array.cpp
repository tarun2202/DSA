/*	1122. Relative Sort Array
	Given two arrays a1 and a2, the elements of a2 are distinct, and all elements in a2 are also in a1.
	Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
	Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
		Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
		Output: [2,2,2,1,4,3,3,9,6,7,19]
		
	time complexity: O(nlogn)
	space complexity: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1, pair<int,int> p2){
	if (p1.second != INT_MAX ||  p2.second != INT_MAX)
		return p1.second < p2.second;
	return p1.first < p2.first;		
}
int main(){
	int n,m;
	cin>>n;
	vector<int>arr1(n);
	vector<int>arr2(m);
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	cin>>m;	
	for(int i=0;i<m;i++)
		cin>>arr2[i];
	vector<int>rank(1001,INT_MAX);
	for(int i=0;i<n;i++)
		rank[arr2[i]]=i;
	vector<pair<int,int> >vec;
	for(int i=0;i<n;i++){
		int x=arr1[i];
		int y=rank[arr1[i]];
		vec.push_back({x,y});
	}
	cout<<endl;			
	sort(vec.begin(),vec.end(),compare);
	for(int i=0;i<n;i++)
		cout<<vec[i].first<<" ";		
}
