/*	Find the Closest Element in BST
	Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given 
	integer.
		Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
		K = 13
		Output: 2
		
	naive approach-->   TC: O(N)	SC: O(N)
	optimal approach--> TC: O(H)	SC: O(H)	
*/

class Solution
{
    public:
    void inorderTraversal(Node *root, vector<int>&ans){
    	if(root){
    		inorderTraversal(root->left, ans);
			ans.push_back(root->data);
			inorderTraversal(root->right, ans);	
		}
	}
	int minDiff(Node *root, int K){
		if(root==NULL)
			return -1;
		vector<int> inorder;
		inorderTraversal(root, ans);
		int ans=INT_MAX;
		for(int i=0;i<inorder.size();i++)
			ans=min(ans,abs(inorder[i]-K));
		return ans;		
	}
};
