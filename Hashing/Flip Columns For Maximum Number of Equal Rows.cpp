/*	1072. Flip Columns For Maximum Number of Equal Rows
	You are given an m x n binary matrix matrix. You can choose any number of columns in the matrix and flip every 
	cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
	Return the maximum number of rows that have all values equal after some number of flips.
		input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
		output: 2
	
	time complexity: O(m*n*log(something))
	space complexity: O(n)	
*/

#include <bits/stdc++.h>
using namespace std;
int maxEqualRowAfterFlip(vector<vector<int>>&mat, int m, int n){
    map<vector<int>,int>mp;
    for(int i=0;i<m;i++)
        mp[mat[i]]++;
    int ans=0;
    for(int i=0;i<m;i++){
        vector<int>onesCompRow(n,0);
        for(int j=0;j<n;j++)
            onesCompRow[j]=(mat[i][j]^1);
        ans=max(ans,mp[onesCompRow]+mp[mat[i]]);    
    } 
    return ans;   

}  
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    int ans=maxEqualRowAfterFlip(mat, m, n); 
    cout<<ans;       
}

