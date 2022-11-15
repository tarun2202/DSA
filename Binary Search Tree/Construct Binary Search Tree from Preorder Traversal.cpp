/*	1008. Construct Binary Search Tree from Preorder Traversal
	Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
		Input: preorder = [8,5,1,7,10,12]
		Output: [8,5,10,1,7,null,12]

	naive approach
		time complexity: O(N^2)
		space complexity:O(h)

	optimised approach
		time complexity: O(N)
		space complexity:O(N)
*/

class Solution {
public:
    // naive approach--> TC: O(N^2)     SC: O(N)
    /*TreeNode *makeBST(vector<int> &preorder, int i, int j){
        if(i>j)     //base case
            return NULL;
        
        // The first node in preorder traversal is root.
        TreeNode *root=new TreeNode(preorder[i]);
        
        // If the current subarray has only one element, no need to recur
        if(i==j)
            return root;
        
        // Search for the first element greater than root
        int itr;
        for(itr=i;itr<=j;itr++)
            if(preorder[itr] > root->val)
                break;
        // dividing the preorder[] into LST, RST using the index 'itr' 
        root->left=makeBST(preorder, i+1, itr-1);
        root->right=makeBST(preorder, itr, j);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //int preIndex=0;
        int n=preorder.size();
        if(n==0)
            return NULL;
        return makeBST(preorder, 0, n-1);
    }*/
    
    //optimised approach using NGE vector  TC:O(N)  SC: O(N)
    TreeNode *makeBST(vector<int>&preorder, int i, int j, vector<int> &NGE){
        if(i>j)
            return NULL;
        TreeNode *root= new TreeNode(preorder[i]);
        root->left=makeBST(preorder, i+1, NGE[i]-1, NGE);
        root->right=makeBST(preorder, NGE[i], j, NGE);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0)
            return NULL;
        vector<int> NGE(n);
        stack<int>stk;
        stk.push(0);
        for(int i=1; i<preorder.size();i++){
            while(!stk.empty() && preorder[i]>preorder[stk.top()]){
                NGE[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            NGE[stk.top()]=n;
            stk.pop();
        }
        return makeBST(preorder, 0, n-1, NGE);
    }
};
