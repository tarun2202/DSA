/*	572. Subtree of Another Tree
	Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same 
	structure and node values of subRoot and false otherwise.
		Input: root = [3,4,5,1,2], subRoot = [4,1,2]
		Output: true
		
	naive approach-->  	  TC: O(N^2) 	SC: O(N)	
*/

// naive approach
/*class Solution {
public:
    bool areSame(TreeNode* r1, TreeNode *r2){
        if(!r1 && !r2)      
            return true;
        if(!r1 || !r2)
            return false;
        return r1->val==r2->val && areSame(r1->left, r2->left) && areSame(r1->right, r2->right);
    }
    void traverse(TreeNode * root, TreeNode* subRoot, bool &ans){
        if (areSame(root, subRoot)){
            ans=true;
            return;
        }
        if(!root)   return;
        traverse(root->left,subRoot,ans);
        traverse(root->right, subRoot, ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        traverse(root, subRoot, ans);
        return ans;
    }
};*/



