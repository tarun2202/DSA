/*	701. Insert into a Binary Search Tree
	You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root 
	node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
	Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after 
	insertion. You can return any of them.
		Input: root = [4,2,7,1,3], val = 5
		Output: [4,2,7,1,3,5]
	
	time complexity: 
	space complexity: 	
*/

class Solution {
public:
    /*TreeNode* insertIntoBST(TreeNode* root, int val) {
        // when the three is empty, val to be inserted is my root node
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* parent=NULL;  //to know where to insert the new item
        TreeNode* node=root;
        while(node){
            parent=node;
            if(val>node->val)
                node=node->right;
            else
                node=node->left;
        }
        // when reached the appropriate NULL, where to insert the new item- 
        if(parent->val<val)
            parent->right=new TreeNode(val);
        else
            parent->left=new TreeNode(val);
        return root;
    }*/
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        if(!root)
            return new TreeNode(key); 
        
        if(root->val > key) 
            root->left = insertIntoBST(root->left,key);
        else 
            root->right = insertIntoBST(root->right,key);
        return root;
        
    }
};
