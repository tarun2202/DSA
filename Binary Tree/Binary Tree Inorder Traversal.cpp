/*	94. Binary Tree Inorder Traversal
	Given the root of a binary tree, return the inorder traversal of its nodes' values.
		Input: root = [1,null,2,3]
		Output: [1,3,2]	

	Method 1: using recursion
		TC: O(n)	SC: O(h)
	Method 2: iterative appraoch
		TC: O(n)	SC: O(n)	
*/

class Solution {
public:
    //Method 1: using recursion
    /*vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }*/
    
    // Method 2: iterative approach using stack
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
            pair<TreeNode*,int> p= st.top();
            st.pop();
            if(p.second==1)
                ans.push_back(p.first->val);
            else{
                if(p.first->right)
                    st.push({p.first->right,0});
                st.push({p.first,1});
                if(p.first->left)
                    st.push({p.first->left,0});
            }
        }
        return ans;
    }
};
