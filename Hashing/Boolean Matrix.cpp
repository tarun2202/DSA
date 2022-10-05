/*	Boolean Matrix
	Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell 
	matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.
		Input: R = 2, C = 2  matrix[][] = {{1, 0},{0, 0}}
		Output: {{1, 1},{1 0}}
		
	Naive Approach--> 	  TC: O((R*C)(R+C))		SC: O(R*C)
	Optimised Approach--> TC: O(R * C)			SC: O(R + C) 	
*/

#include<bits/stdc++.h>
using namespace std;

/*naive approach: 
1) Create a temparory matrix of size rxc.  
2) Populate the cell with 1 for which the array cell arr[i][j] is having value 1.
		time complexity: O((r*c)(r+c))
		space complexity: O(r*c)		*/

//optimised approach
void booleanMatrix(vector<vector<int> > &matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> row(m,0), col(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1)
                matrix[i][j]=1;
        }
    }
}
int main(){
	int r,c;
	cin>>r>>c;
	vector<vector<int> >matrix(r,vector<int>(c));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>matrix[i][j];
	booleanMatrix(matrix);		
	for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }    
        cout << endl;
    }		
}
