/*	235. Lowest Common Ancestor of a Binary Search Tree
	Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
		Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
		Output: 6
		Explanation: The LCA of nodes 2 and 8 is 6.
		
	time complexity: O(H)
	space complexity: O(1)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // assuming p and q exists in BST
        int minm=min(p->val, q->val);
        int maxm=max(p->val, q->val);
        while(root){
            if(root->val==q->val|| root->val==p->val)
                return root;
            if(minm<root->val && maxm>root->val)
                return root;
            else if(root->val<minm && root->val <maxm)
                root=root->right;
            else 
                root=root->left;
        }
        return NULL;
    }
};
