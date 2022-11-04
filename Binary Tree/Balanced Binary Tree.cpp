/*	110. Balanced Binary Tree
	Given a binary tree, determine if it is height-balanced.
	A tree is height balanced if difference between heights of left and right subtrees is not more than one for all 
	nodes of tree. 
	Input:
    	   10
    	  /  \
    	20   30 
  	   /  \
 	  40  60
	Output: 1
	Explanation: The max difference in height of left subtree and right subtree is 1. Hence balanced. 
*/

class Solution {
public:
    //naive approach: O(n^2)
    /*int getHeight(TreeNode *root){
        if(root==NULL)
            return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh=getHeight(root->left);
        int rh=getHeight(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }*/
    
    //effecient approach: O(n)
    int height(TreeNode *root, bool &balanced){
        if(root==NULL)
            return 0;
        int lh=height(root->left,balanced);
        int rh=height(root->right,balanced);
        if(abs(lh-rh)>1)
            balanced=false;
        return 1+max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        bool balanced=true;
        int res=height(root,balanced);
        return res>0 ? balanced:false;
    }
};
