/*	103. Binary Tree Zigzag Level Order Traversal
	Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left 
	to right, then right to left for the next level and alternate between).
		Input: root = [3,9,20,null,null,15,7]
		Output: [[3],[20,9],[15,7]]
	
	time complexity: O(n)
	space complexity: O(2n) ~ O(n) ->proportional to the no of nodes in each level
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)  //base base, when tree is empty
            return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;  
        q.push(root);
        int level=0;    //to check if level is odd or even
        int len;    //size of queue in each level
         //to store the node value, inorder to print in reverse order.
        stack<int>st;  
        // till the queue becomes empty
        while(!q.empty()){
            len=q.size();   //size of queue at current level of tree
            vector<int>v;   //to store the node value in each level
            for(int i=0;i<len;i++){
                TreeNode* n=q.front();
                q.pop();
                if(level%2!=0)
                    st.push(n->val);
                else
                    v.push_back(n->val);
                if(n->left)     //if left subtree exists
                    q.push(n->left); 
                if(n->right)    //if right subtree exists
                    q.push(n->right);
            }
            if(level%2!=0){
                //when level is odd, empty the stack to v i.e., put node value in reverse order to get the desired results
                while(!st.empty()){ 
                    v.push_back(st.top());
                    st.pop();
                }
            }
            level++;    //incrementing the level
            ans.push_back(v);
        }
        return ans;
    }
};
