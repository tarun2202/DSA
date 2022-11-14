/*	230. Kth Smallest Element in a BST
	Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the 
	values of the nodes in the tree.
		Input: root = [5,3,6,2,4,null,null,1], k = 3
		Output: 3
	
	naive approach--> 		TC: O(nlogn)	SC: O(N)
	better appraoch--> 		TC: O(N)	SC: O(N)
	optimised approach-->   TC: O(N)	SC: O(1)	
*/

class Solution {
public:
    // better approach- TC: O(N)    SC: O(N)
    /*void inorderTraversal(TreeNode *root, vector<int>&ans){
        if(root){
            inorderTraversal(root->left, ans);
            ans.push_back(root->val);
            inorderTraversal(root->right, ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        vector<int>ans;
        inorderTraversal(root, ans);
        return ans[k-1];
    }*/
    
    //optimised approach--> TC: O(N)    SC: O(1)
    void traversal(TreeNode *root, int k, int &count, int &ans){
        if(!root)
            return;
        traversal(root->left, k, count, ans);
        count++;
        if(count == k){
            ans=root->val;
            return;
        }
        traversal(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0, ans=-1;
        traversal(root, k, count, ans);
        return ans;
    }
};
