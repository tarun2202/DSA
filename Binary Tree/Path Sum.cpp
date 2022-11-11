/*	112. Path Sum
	Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such 
	that adding up all the values along the path equals targetSum.
		Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
		Output: true
		Explanation: The root-to-leaf path with the target sum is shown.
		
	time complexity: O(N)
	space complexity: O(H) ~ O(N) in case of perfectly right/ left skewed tree.	
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if tree is empty
        if(root==NULL)
            return false;
        
        bool ans=false;
        int remSum=targetSum-root->val;
        
        //when we reached the leaf node and remSum becomes 0- current path sum ==targetSum
        if(root->left==NULL && root->right==NULL && remSum==0)
            return true;
        
        //otherwise check both subtrees
        if(root->left)
            ans=ans || hasPathSum(root->left, remSum);
        if(root->right)
            ans=ans || hasPathSum(root->right, remSum);
        
        return ans;
    }
};
