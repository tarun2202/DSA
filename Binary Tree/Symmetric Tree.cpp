/*	101. Symmetric Tree
	Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
	Input: 
        5
       /   \
      10     10
     /  \     \
    20  20     30
	Output: False
	
	time complexity: O(n)
	space complexity: O(h)
*/

class Solution {
public:
    bool isMirrorImage(TreeNode* r1, TreeNode* r2){
        if(!r1 and !r2)
            return true;
        if(!r1 or !r2)
            return false;
        return r1->val==r2->val && 
               isMirrorImage(r1->left, r2->right) && 
               isMirrorImage(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirrorImage(root->left, root->right);
    }
};
