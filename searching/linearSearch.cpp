#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int>&arr,int target){
	for(int i=0;i<arr.size();i++){
		if(target == arr[i])
			return i;		
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int target;
	cin>>target;	
	int res = linearSearch(arr,target);	
	if(res!=-1)
		cout<<"element "<<target<<" found at index "<<res;
	else
		cout<<"element "<<target<<" not found!";
}
