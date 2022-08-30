#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void calSum(vector<int> &arr,int idx,int sum){
	if(idx==arr.size()){
		ans.push_back(sum);
		return;
	}
	//calSum(arr,idx+1,sum+arr[idx]);
	calSum(arr,idx+1,sum);
	calSum(arr,idx+1,sum+arr[idx]);
	
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	calSum(arr,0,0);
	//sort(ans.begin(),ans.end());
	for(int i=0;i<pow(2,n);i++)
		cout<<ans[i]<<" ";	
}
