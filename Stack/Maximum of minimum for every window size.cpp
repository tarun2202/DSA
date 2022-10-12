/*	Maximum of minimum for every window size
	Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
	Note: Window size varies from 1 to the size of the Array.
		input: arr[] = {10,20,30,50,10,70,30}
		output: {70 30 20 10 10 10 10}
	
	naive approach    -->	TC: O(n^3)		SC: O(1) 
	optimised approach--> 	TC: O(n)		SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// naive approach
/*vector<int> maxOfMin(vector<int> &arr, int n){
	vector<int>ans(n,0);
	for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int minm=INT_MAX;
            for(int k=i;k<=j;k++)
                 minm=min(minm,arr[k]);
            int length=j-i;
            ans[length]=max(ans[length],minm);
        }
    }
    return ans;
}*/

// optimised approach
vector<int> maxOfMin(vector<int> &arr, int n){
	stack<int>s;
    vector<int>right(n+1,n);
    vector<int>left(n+1,-1);
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]>arr[i]){
            right[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[s.top()]>arr[i]){
            left[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }    
    vector<int>ans(n+1,0);
    for(int i=0;i<n;i++){
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],arr[i]);
    }
    for(int i=n-1;i>=1;i--)
        ans[i]=max(ans[i],ans[i+1]);
    vector<int>res(n);
    for(int i=1;i<=n;i++)
        res[i-1]=ans[i];
    return res;    
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int>ans= maxOfMin(arr,n);
	for(int i=0;i<ans.size();i++)    
        cout<<ans[i]<<" ";	
}
