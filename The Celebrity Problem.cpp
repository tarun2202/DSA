/*	The Celebrity Problem
	A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people,
	find if there is a celebrity in the party or not.
	A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  
	is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
	Note: Follow 0 based indexing.
		input: N=4	{{0, 0, 1, 0},
                	{0, 0, 1, 0},
                	{0, 0, 0, 0},
                	{0, 0, 1, 0}};
        output: 2
	
	Efficient Approach--> TC: O(n)    SC: O(n)
	Optimal Approach-->   TC: O(n)    SC:O(1)	        	
*/

#include<bits/stdc++.h>
using namespace std;

// Naive approach
//function to check if celebrity exists or not.
/*int findCelebrity(vector<vector<int>> &arr,int n){
	stack<int>st;
	//pushing all the persons in the party in stack
	for(int i=0;i<n;i++)
		st.push(i);
	// uses the method of elemination to check celebrity on the last 2 element of stack till the stack size is >=2	
	while(st.size()>=2){
		//selecting 1st element
		int i=st.top(); st.pop();
		//selecting 2nd element
		int j=st.top(); st.pop();
		if(arr[i][j]==1)
			//i knows j--> i can't be a celebrity
			st.push(j);
		else
			//i doesn't know j--> j can't be a celebrity 
			st.push(i);	
	}
	// only element left is our potential celebrity candidate	
	int pot=st.top();	st.pop();
	for(int i=0;i<n;i++){
		// checking for is our potential candidate is celebrity or not.
		if(i!=pot){
			if(arr[pot][i]==1 or arr[i][pot]==0)
				return -1;
		}
	}
	//potential candidate is our celebrity
	return pot;
}*/

// Optimal Approach
int findCelebrity(vector<vector<int>> &arr,int n){
	int i=0, j=n-1;
	while(i<j){
		if(arr[j][i]==1)
			// j knows i: j can't be a celebrity
			j--;
		else
			// j doesn't know i: i can be a celebrity 
			i++;	
	}	
	// at end the potential celebrity can be at index i
	int pot=i;
    // checking for is our potential candidate is celebrity or not.
	for(int i=0;i<n;i++){
		if(i!=pot){
			if(arr[pot][i]==1 or arr[i][pot]==0)
				return -1;
		}
	}
    //potential candidate is our celebrity
	return pot;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	int ans=findCelebrity(arr,n);
	cout<<ans;		
}

