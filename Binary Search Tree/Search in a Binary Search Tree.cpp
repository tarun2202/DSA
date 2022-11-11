/*	700. Search in a Binary Search Tree
	You are given the root of a binary search tree (BST) and an integer val.
	Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a
	node does not exist, return null.
		Input: root = [4,2,7,1,3], val = 2
		Output: [2,1,3]
	
	time complexity: O()
	space complexity: O()	
*/

class Solution {
public:
    //method 1: using iterative approach
    /*TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *node=root;
        while(node!=NULL){
            if(node->val==val)
                return node;
            else if(node->val < val)
                node=node->right;
            else
                node=node->left;
        }
        return NULL;
    }*/
        
    //method 2: using recursion-
    TreeNode* searchBST(TreeNode* root, int val) {   
        TreeNode *curr;
        if(root==NULL || root->val==val)
            return root;
        else if(root->val<val)
            curr=searchBST(root->right, val);
        else
            curr=searchBST(root->left, val);
        return curr;
    }
};
