/*	543. Diameter of Binary Tree
	Given the root of a binary tree, return the length of the diameter of the tree.
	The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or 
	may not pass through the root.
	
	The length of a path between two nodes is represented by the number of edges between them.
	
		Input: root = [1,2,3,4,5]
		Output: 3
		Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].	
	
	time complexity: O(n)
	space complexity: O(h)	
*/

class Solution {
public:
    // TC: O(n^2)
    /*int height(TreeNode* root){
        if(root==NULL)
            return -1;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lHeight=height(root->left);
        int rHeight=height(root->right);
        
        int lDiameter=diameterOfBinaryTree(root->left);
        int rDiameter=diameterOfBinaryTree(root->right);
        
        return max(rHeight+lHeight+2, max(rDiameter, lDiameter));
    }*/
    
    //TC: O(n)
    int getHeight(TreeNode* root, int &ans){
        if(root==NULL)
            return -1;
        int lh=getHeight(root->left,ans);
        int rh=getHeight(root->right,ans);
        ans=max(ans,2+lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        getHeight(root,ans);
        return ans;
    }
};
