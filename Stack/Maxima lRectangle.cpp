/*	85. Maximal Rectangle
	Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and 
	return its area.
	input: mat= 1 0 1 0 0
				1 0 1 1 1
				1 1 1 1 1 
				1 0 0 1 0
	output: 6
	
	time complexity:  O(MxN)
	space complexity: O(N)			
*/

#include<bits/stdc++.h>
using namespace std;
int maximalRectangle(vector<vector<int>> &mat) {
    int m=matrix.size();
    int n=matrix[0].size();
    if(m==0 && n==0)
        return 0;
	        
}
int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>>mat(m,vector<int>(n));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
	int ans=maximalRectangle(mat);
	cout<<ans;		
}
