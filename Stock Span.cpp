/*	Stock span problem
	The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we 
	need to calculate the span of stocks price for all n days. 
	The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before
	the given day, for which the price of the stock on the current day is less than or equal to its price on the 
	given day.
		Input: N = 7, price[] = [100 80 60 70 60 75 85]
		Output: [1 1 1 2 1 4 6]
	
	naive approach-->	  TC: O(n^2) 	SC: O(1)
	optimised approach--> TC: O(n)		SC: O(n)		
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
/*vector<int> calculateSpan(vector<int> &prices, int n){
	vector<int> span(n);
	span[0]=1;
	for(int i=1;i<n;i++){
		span[i]=1;
		for(int j=i-1;j>=0 && prices[i]>=prices[j]; j--)
			span[i]++;
	}
	return span;
}*/

//optimised approach
vector<int> calculateSpan(vector<int> &prices, int n){
	vector<int> span(n);
	stack<int>st;
	st.push(0);
	span[0]=1;
	for(int i=1;i<n;i++){
		while(!st.empty() && prices[i]>=prices[st.top()])
			st.pop();
		if(st.size()==0)
			span[i]=i+1;
		else
			span[i]=i-st.top();
		st.push(i);			
	}	
	return span;
}
int main(){
	int n;
	cin>>n;
	vector<int>prices(n);
	for(int i=0;i<n;i++)
		cin>>prices[i];
	vector<int> ans=calculateSpan(prices,n);
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";	
}
