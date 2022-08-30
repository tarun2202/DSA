/*
	Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
	NOTE: You may return the answer in any order.
	
	input: n=4, k=2
	output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
	
	time complexity: O(k.(n^k))
	space complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;
void findCombination(vector<int> &temp,int n,int k,int idx){
	if(temp.size()==k){
		cout<<" ( ";
		for(int j=0;j<temp.size();j++)
			cout<<temp[j]<<" ";
		cout<<")";	
	}
	for(int i=idx;i<=n;i++){
		temp.push_back(i);
		findCombination(temp,n,k,i+1);
		temp.pop_back();
	}
}
int main(){
	int n;
	int k;
	cin>>n>>k;
	vector<int> arr;
	findCombination(arr,n,k,1);
}
