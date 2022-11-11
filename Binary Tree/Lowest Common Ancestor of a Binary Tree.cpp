/*	236. Lowest Common Ancestor of a Binary Tree
	Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
		Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
		Output: 3
		Explanation: The LCA of nodes 5 and 1 is 3.
		
	time complexity: O(N)
	space complexity: O(N)	
*/

class Solution {
public:
    // effecient approach- without using extra vectors for storing path of node p and q.
    
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }*/
    
    // naive approach- storing the path of node p and q
    
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path1, vector<TreeNode*> &path2, vector<TreeNode*> &temp){
        if(root==NULL)
            return;
        temp.push_back(root);
        if(root->val==p->val){
            for(int i=0;i<temp.size();i++)
                path1.push_back(temp[i]);
        }
        if(root->val==q->val){
            for(int i=0;i<temp.size();i++)
                path2.push_back(temp[i]);
        }
        traverse(root->left, p, q, path1, path2, temp);
        traverse(root->right, p, q, path1, path2, temp);
        temp.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1, path2, temp;
        traverse(root, p, q, path1, path2, temp);
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i]->val!=path2[i]->val)
                break;
            i++;
        }
        return path1[i-1];
    }
};
