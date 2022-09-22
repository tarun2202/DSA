/*	Given two sorted array arr1 and arr2 in increasing order. merge Two sorted array as one sorted array.
	
	time complexity: naive--> O(m+n log(m+n))
					 optimised--> O(m+n)
	space complexity: O(m+n)				 

*/
#include<bits/stdc++.h>
using namespace std;

//naive approach:
/*vector<int> mergeProcess(vector<int>arr1,int m,vector<int>arr2,int n){
	vector<int>res(m+n);
	int i;
	for(i=0;i<m;i++)
		res[i]=arr1[i];
	int j,k=0;
	for(j=i;j<n+m;j++){
		res[j]=arr2[k];
		k++;	
	}
	sort(res.begin(),res.end());
	return res;
}*/

//optimised approach:
vector<int> mergeProcess(vector<int>&arr1,int m,vector<int>&arr2,int n){
	vector<int>res(m+n);
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<=arr2[j]){
			res[k++]=arr1[i++];
		}
		else{
			res[k++]=arr2[j++];
		}
	}
	while(i<m){
		res[k++]=arr1[i++];
	}
	while(j<n){
		res[k++]=arr2[j++];
	}
	return res;
}

int main(){
	int m,n;
	cin>>m;
	vector<int>arr1(m);
	for(int i=0;i<m;i++)
		cin>>arr1[i];
	cin>>n;
	vector<int>arr2(n);	
	for(int i=0;i<n;i++)
		cin>>arr2[i];
	vector<int> res=mergeProcess(arr1,m,arr2,n);
	for(int i=0;i<m+n;i++)
		cout<<res[i]<<" ";
}
