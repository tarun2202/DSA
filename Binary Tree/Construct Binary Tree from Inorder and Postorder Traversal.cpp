/*	106. Construct Binary Tree from Inorder and Postorder Traversal
	Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
	postorder is the postorder traversal of the same tree, construct and return the binary tree.
		Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
		Output: [3,9,20,null,null,15,7]
		
	time complexity: O(N)
	space complexity: O(N)	
*/

class Solution {
public:  
    TreeNode *constructTree(vector<int> &inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int> &m){
        if(inStart>inEnd || postStart>postEnd)
            return NULL;
        TreeNode *root= new TreeNode(postorder[postEnd]);
        int elem = m[root->val];
        int nelem = elem-inStart;
        root->left= constructTree(inorder, inStart, elem-1, postorder, postStart, postStart+nelem-1, m);
        root->right= constructTree(inorder, elem+1, inEnd, postorder, postStart+nelem, postEnd-1, m);
        return root;
    }
    
    TreeNode * buildTree(vector<int>& inorder, vector<int> &postorder){
        if(inorder.size()!=postorder.size())
            return NULL; 
        
        int postStart=0, postEnd=postorder.size()-1;
        int inStart=0, inEnd=inorder.size()-1;
        
        unordered_map<int,int> m;
        for(int i=inStart;i<=inEnd;i++)
            m[inorder[i]]=i;
        
        return constructTree(inorder, inStart, inEnd, postorder, postStart, postEnd, m);
    }
};
