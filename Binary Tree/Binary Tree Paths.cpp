/*	Binary Tree Paths
	Given the root of a binary tree, return all root-to-leaf paths in any order.
	Input:
         10
       /    \
      20    30
     /  \
    40   60
	Output: 10 20 40 #10 20 60 #10 30 #
	
	time complexity: O(n)
	space complexity: O(h)
*/

class Solution {
public:
	void solver(TreeNode* root, vector<string>& res, string temp){
		if(root==NULL)
			return;
		if(!root->left and !root->right){
			res.push_back(temp);
			return;
		}
		if(root->left)	solver(root->left, res,temp+"->"+to_string(root->left->val));
		if(root->right)	solver(root->right,res,temp+="->"+to_string(root->right->val));	
	}
	vector<string> binaryTreePaths(TreeNode*root){
		vector<string>res;
		if(root==NULL)
			return res;
		solver(root, res, to_string(root->val));
		return res;	
	}	
};
