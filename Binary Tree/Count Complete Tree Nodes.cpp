/*	222. Count Complete Tree Nodes
	Given the root of a complete binary tree, return the number of the nodes in the tree.
		Input: root = [1,2,3,4,5,6]
		Output: 6
		
	naive appraoch    --> TC: O(n)			SC: O(H)=O(logn)
	effecient approach--> TC: O(logn.logn)	SC: O(logn)	
*/

class Solution {
public:
    //naive approach
    /*int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }*/
    
    //effecient approach
    int countNodes(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh)
            return (1<<lh)-1;
            //return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findLeftHeight(TreeNode* root){
        int height;
        while(root!=NULL){
            height++;
            root=root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* root){
        int height;
        while(root!=NULL){
            height++;
            root=root->right;
        }
        return height;
    }
};
