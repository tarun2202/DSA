/*	Search in 2D Matrix
	searches for a value in an mxn matrix. This matrix has the following properties:
		-> Integers in each row are sorted from left to right.
		-> The first integer of each row is greater than the last integer of the previous row.
	input:3 4					output: true
		  1 3 5 7						false
		  10 11 16 20
		  23 30 34 60
		  2
		  3
          13
	time complexity: O(logm)+O(logn) ~ O(log(m*n))
	space complexity: O(1)	  	

*/

//naive approach: to iterate over the whole array and upon finding the target return true, else return false.
				//time complexity:O(m*n)
				
//optimised approach: using binary search concept
#include <bits/stdc++.h>
using namespace std;
int search2DMatrix(vector<vector<int>>&mat,int target){
	int m=mat.size();
	int n=mat[0].size();
	if(!mat.size()) 
		return -1;
	int left=0,right=m*n-1;
	int mid;
	while(left<=right){
		mid=left+(right-left)/2;
		if(mat[mid/n][mid%n]==target)
			return 1;
		//arr[x]=arr[m/col_size][arr%col_size]
		else if(target>mat[mid/n][mid%n])
			left=mid+1;
		else 
			right=mid-1;
	}
	return -1;
}
int main() {
    int m,n;
	cin>>m>>n;
	vector<vector<int>>mat(m,(vector<int>(n)));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
	int t;
	cin>>t;
	int ans;
	while(t--){
		int target;
		cin>>target;
		ans=search2DMatrix(mat,target);
		if(ans==-1)
			cout<<"false"<<endl;
		else 
			cout<<"true"<<endl;
	}
}

