/*	105. Construct Binary Tree from Preorder and Inorder Traversal
	Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
	inorder is the inorder traversal of the same tree, construct and return the binary tree.
		Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
		Output: [3,9,20,null,null,15,7]
 	
	time complexity: O(N)
	space complexity: O(N)
*/

class Solution {

public:
    TreeNode *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &m){
        if(inStart>inEnd || preStart>preEnd)
            return NULL;
        TreeNode *root=new TreeNode(preorder[preStart]);
        int elem = m[root->val];
        int nelem = elem-inStart;
        root->left= constructTree(preorder, preStart+1, preStart+nelem, inorder, inStart, elem-1, m);
        root->right= constructTree(preorder, preStart+nelem+1, preEnd, inorder, elem+1, inEnd, m);
        return root;
    }
    
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart=0, preEnd=preorder.size()-1;
        int inStart=0, inEnd=inorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, m);
    
    } 
};
