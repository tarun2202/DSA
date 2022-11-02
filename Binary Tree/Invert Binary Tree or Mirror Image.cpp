/*	226. Invert Binary Tree
	Given the root of a binary tree, invert the tree, and return its root.\
		Input: root = [4,2,7,1,3,6,9]
		Output: [4,7,2,9,6,3,1]
	
	time complexity: O(n)
	space complexity: O(h)	
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
