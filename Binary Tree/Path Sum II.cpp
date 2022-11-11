/*	113. Path Sum II
	Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node
	values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
	A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no 
	children.
	
		Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
		Output: [[5,4,11,2],[5,8,4,5]]
		Explanation: There are two paths whose sum equals targetSum:
					5 + 4 + 11 + 2 = 22
					5 + 8 + 4 + 5 = 22
	
	time complexity: O(n)
	space complexity: O(n)				
*/

class Solution {
public:
    
    void dfs(TreeNode* root, int newtarget, vector<int>& path, vector<vector<int>> &ans) {
        // if current root is null return
        if (!root) 
            return; 
        path.push_back(root->val);
        // new target will be the privious target- the value of that node
        newtarget -= root->val; 
        
        // check whether it is a leaf node or not and currSum is equal to target sum, if yes- return current path as answer
        if (!root->left && !root->right && newtarget==0)  
                ans.push_back(path);
        else {
            dfs(root->left, newtarget, path, ans);
            dfs(root->right, newtarget, path, ans);
        }
        path.pop_back(); // for the backtracking
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);// using dfs to traverse on each node
        return ans;
    }
};
