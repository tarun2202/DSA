/*	124. Binary Tree Maximum Path Sum
	The path sum of a path is the sum of the node's values in the path.
	Given the root of a binary tree, return the maximum path sum of any non-empty path.
		Input:
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
	Output: 32
	Explanation: Path in the given tree goes like 10 , 2 , 20 which gives the max sum as 32.
	
	time complexity: O(n)
	space complexity: O(h)
*/

class Solution {
public:
    pair<int, int> getMaxPath(TreeNode *root){
        if(!root) 
            return {INT_MIN, 0};
        pair<int, int> lst = getMaxPath(root->left);
        pair<int, int> rst = getMaxPath(root->right);
        int max_sum_path = max(root->val+max(0, lst.second)+max(0, rst.second),
            max(lst.first, rst.first));
        int max_uni_path = root->val + max({0, lst.second, rst.second});
        return {max_sum_path, max_uni_path};
    }
    int maxPathSum(TreeNode* root) {
        pair<int,int> res=getMaxPath(root);
        return res.first;
    }
};
