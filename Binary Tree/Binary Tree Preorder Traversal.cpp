/*	144. Binary Tree Preorder Traversal
	Given the root of a binary tree, return the preorder traversal of its nodes' values.
		Input: root = [1,null,2,3]
		Output: [1,2,3]
	
	method 1: using recursion
		time coomplexity: O(n)
		space complexity: O(h)
	method 2: iterative approach using stack
		time complexity: O(n)
		space complexity: O(h)		
*/

class Solution {
public:
    vector<int>preorder;
    //recursive approach
    /*vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return preorder;
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
    }*/
    
    //iterative approach
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        stack<TreeNode *>st;
        st.push(root);
        while(st.empty()==false){
            TreeNode* node=st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return preorder;
    }
};
