/*	Agressive Cows
	Farmer John has built a new long barn, with N stalls. The stalls are located along a straight line at 
	positions x1,x2,....,xn. His C cows dont like this barn layout and become aggressive towards each other 
	once put into a stall. To prevent the cows from hurting each other, Farmer John wants to assign the cows 
	to the stalls, such that the minimum distance between any two of them is as large as possible. What is 
	the largest minimum distance?
		Input:	5
				1 2 8 4 9
				1
				3
		Output: 3
	time complexity: 
	space complexity:			
*/

#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>pos,int cows,int mid){
	int count=1, prev=pos[0];
	for(int i=1;i<pos.size();i++){
		if(pos[i]-prev<mid)
			continue;
		else{
			count++;
			prev=pos[i];
		}	
	}
	return count>=cows;
}
int arrangeCows(vector<int>&pos,int n,int cows){
	int left=INT_MAX,right=0,mid;
	if(cows>n)
		return -1;
	for(int i=0;i<=n-2;i++){
		left=min(left,pos[i+1]-pos[i]);
		right=pos[n-1]-pos[0];
	}
	while(left<=right){
		mid=(left+right)/2;
		if(!isPossible(pos,cows,mid))
			right=mid-1;
		else{
			if(!isPossible(pos,cows,mid+1))
				return mid;
			else
				left=mid+1;	
		}	
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>pos(n);
	for(int i=0;i<n;i++)
		cin>>pos[i];
	int t;
	cin>>t;
	while(t--){
		int cows;
		cin>>cows;
		int ans=arrangeCows(pos,n,cows);
		cout<<ans;
	}	
}
