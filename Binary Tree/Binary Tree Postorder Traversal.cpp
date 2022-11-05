/*	145. Binary Tree Postorder Traversal
	Given the root of a binary tree, return the postorder traversal of its nodes' values.
		Input: root = [1,null,2,3]
		Output: [3,2,1]
	
	Method 1: using recursion
		TC: O(n)	SC: O(h)
	Method 2: iterative appraoch using 2 stack
		TC: O(n)	SC: O(2n)		
	Method 3: iterartive approach using 1 stack
		TC: O(n)	SC: O(n)	
*/

class Solution {
public:
    vector<int>ans;
    //method 1: using recursion
    /*vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }*/
    
    //method 2:iterative approach using 2 stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postOrder;
        if(root==NULL)
            return postOrder;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(s1.empty()==false){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left)
                s1.push(root->left);
            if(root->right)
                s1.push(root->right);
        }
        while(!s2.empty()){
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        return postOrder;
    }
};
