/*	111. Minimum Depth of Binary Tree
	Given a binary tree, find its minimum depth.
	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
		Input:
            1
          /   \
         3     2
        /
       4           
		Output: 2
		
	time complexity: O(n)
	space complexity: O(h)
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
            return 1;
        int l=INT_MAX, r=INT_MAX;
        if(root->left)
            l=minDepth(root->left);
        if(root->right)
            r=minDepth(root->right);
        return 1+min(l,r);
    }
};
