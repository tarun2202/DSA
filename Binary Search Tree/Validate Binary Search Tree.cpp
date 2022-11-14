/*	98. Validate Binary Search Tree
	Given the root of a binary tree, determine if it is a valid binary search tree (BST).
		Input: root = [5,1,4,null,null,3,6]
		Output: false
		Explanation: The root node's value is 5 but its right child's value is 4.
	
	naive approach--> 	  TC: O(N)	SC: O(H+N) ~ O(N)
	efficient approach--> TC: O(N)	SC: O(H)
*/

class Solution {
public:
    // naive approach--> TC: O(N)   SC: O(N)
    /*void inorderTraversal(TreeNode *root, vector<int> &inorder){
        if(root){
            inorderTraversal(root->left, inorder);
            inorder.push_back(root->val);
            inorderTraversal(root->right, inorder);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return false;
        vector<int> inorder;
        inorderTraversal(root, inorder);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1])
                return false;
        }
        return true;
    }*/
    
    // optimised approach--> TC: O(N)   SC: O(1)    
    void inorderTraversal(TreeNode *root, long &prev, bool &ans){
        if(!root)
            return;
        inorderTraversal(root->left, prev, ans);
        if(prev < root->val)
            prev=root->val;
        else{
            ans=false;
            return;
        }
        inorderTraversal(root->right, prev, ans);
    }
    bool isValidBST(TreeNode* root) {
        long prev=LONG_MIN; //root->val lies in range [INT_MIN, INT_MAX]
        bool ans=true;
        inorderTraversal(root, prev, ans);
        return ans;
    }
    
    // method 2: 
    /*void check(TreeNode *root, long lb, long ub, bool &ans){
        if(!root)   
            return;
        if(root->val<=lb || root->val>=ub){
            ans=false;
            return;
        }
        check(root->left, lb, root->val, ans);
        check(root->right, root->val, ub, ans);
    }
    bool isValidBST(TreeNode* root){
        bool ans=true;
        long lb=LONG_MIN, ub=LONG_MAX;
        check(root, lb, ub, ans);
        return ans;
    }*/
};
