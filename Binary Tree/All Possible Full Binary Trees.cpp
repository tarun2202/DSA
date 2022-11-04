/*	894. All Possible Full Binary Trees
	Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the 
	answer must have Node.val == 0.
	Each element of the answer is the root node of one possible tree. You may return the final list of trees in any 
	order.
		input: n=5
		output: [[0,0,0,0,0,null,null],[0,0,null,null,0,0,0]
*/

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
  		if(n==1)
			return {new TreeNode(0)};
		vector<TreeNode*> ans;
		for(int i=1;i<n;i+=2){
			vector<TreeNode *>lst=allPossibleFBT(i);
			vector<TreeNode *>rst=allPossibleFBT(n-i-1);
			for(int j=0;j<lst.size();j++){
				for(int k=0;k<rst.size();k++){
					TreeNode *root=new TreeNode(0);
					root->left=lst[j];
					root->right=rst[k];
					ans.push_back(root);
				}
			}
		}
		return ans;	  	
    }
};
