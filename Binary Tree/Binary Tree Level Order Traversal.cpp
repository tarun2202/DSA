/*	102. Binary Tree Level Order Traversal
	Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right,
	level by level).
		Input: root = [3,9,20,null,null,15,7]
		Output: [[3],[9,20],[15,7]]
	
	time complexity: O(n)
	space complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int len;
        while(!q.empty()){
            len=q.size();
            vector<int>v;
            for(int i=0;i<len;i++){
                TreeNode* n=q.front();
                q.pop();
                v.push_back(n->val);
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
