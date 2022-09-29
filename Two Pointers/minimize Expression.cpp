/*
	Given three sorted arrays A, B, and C of not necessarily same sizes. Calculate the minimum absolute difference 
	between the maximum and minimum number of any triplet A[i], B[j], C[k] such that they belong to arrays A, B and C 
	respectively, i.e., minimize (max(A[i], B[j], C[k]) – min(A[i], B[j], C[k]))
	
		Input : A : [ 1, 4, 5, 8, 10 ]
        		B : [ 6, 9, 15 ]
        		C : [ 2, 3, 6, 6 ]
		Output : 1
		Explanation: When we select A[i] = 5, B[j] = 6, C[k] = 6, we get the minimum difference as 
					 max(A[i], B[j], C[k]) - min(A[i], B[j], C[k]))
					 = |6-5| = 1 
	
	brute force-->        TC: O(m.n.p)	SC: O(1)
	optimised approach--> TC: O(m+n+p)	SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//naive Approach
/*int findMinimum(vector<int>&A, int m,vector<int>&B, int n,vector<int>&C, int p){
	int ans=INT_MAX;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<p;k++){
				int x=max(A[i],max(B[j],C[k]));
				int y=min(A[i],min(B[j],C[k]));
				ans=min(ans,min(x,y));
			}
		}
	}
	return ans;
}*/

//optimised approach
int findMinimum(vector<int>&A, int m,vector<int>&B, int n,vector<int>&C, int p){
	int ans=INT_MAX;
	int i=0, j=0, k=0;
	while(i<m && j<n && k<p){
		int val=max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));
		ans=min(ans,val);
		int minm=min(A[i],min(B[j],C[k]));
		if(A[i]==minm)	i++;
		else if(B[j]==minm)	j++;
		else k++;
	}
	return ans;	
}

int main(){
	int m,n,p;
	cin>>m;
	vector<int>A(m);
	for(int i=0;i<m;i++)
		cin>>A[i];
	cin>>n;	
	vector<int>B(n);
	for(int i=0;i<n;i++)
		cin>>B[i];
	cin>>p;	
	vector<int>C(p);
	for(int i=0;i<p;i++)
		cin>>C[i];
	int ans=findMinimum(A,m,B,n,C,p);
	cout<<ans;	
}

