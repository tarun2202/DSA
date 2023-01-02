/*	Adjacents are not allowed
	You have a rectangular grid mat of dimension 2 x N. You need to find out the maximum sum such that no two chosen 
	numbers are adjacent, vertically, diagonally or horizontally.
		Input: N = 3
			 mat = {{1, 4, 5}, 
       				{2, 0, 0}}
		Output: 7
		Explaination: Optimal choice is (2, 5).
		
	memorization    : TC: O(N)	SC: O(N)
	tabulation      : TC: O(N)	SC: O(N)
	space optimised	: TC: O(N)	SC: O(1)
*/

class Solution{
public:
    int findMaxSum(int i, int n, vector<vector<int>> &mat, vector<int>&ans){
        // here i: represents column number, and n is total number of columns in mat
        if(i>=n)
            return 0;
        if(ans[i]!=-1)
            return ans[i];
        ans[i]=max(max(mat[0][i], mat[1][i])+findMaxSum(i+2, n, mat, ans), findMaxSum(i+1, n, mat, ans));
        return ans[i];
    }
    int maxSum(int n, vector<vector<int>> mat) {
        int i=0;
        vector<int>ans(n,-1);
        return findMaxSum(i, n, mat, ans);
    }
};
