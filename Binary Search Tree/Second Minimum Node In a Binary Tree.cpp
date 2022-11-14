/*	671. Second Minimum Node In a Binary Tree
	Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in 
	the whole tree.
	If no such second minimum value exists, output -1 instead.
		Input: root = [2,2,5,null,null,5,7]
		Output: 5
		Explanation: The smallest value is 2, the second smallest value is 5.
		
	naive approach--> TC:O(N.logN)	SC: O(N)	
	optimised approach--> TC: O(N)	SC: O(N)
*/

class Solution {
public:
    //naive approach--> TC: O(N.logN)  SC: O(N)
    void Traversal(TreeNode* root, vector<int> &ans){
        if(root){
            ans.push_back(root->val);
            Traversal(root->left, ans);
            Traversal(root->right, ans);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL)
            return -1;
        vector<int>ans;    
        Traversal(root, ans);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]!=ans[i+1])
               return ans[i+1];
        }
        return -1;
    }
    
    //optimised approach--> TC: O(N)    SC: O(N)
    /*void inorder(TreeNode* root, set<int>&s)
    {
        if(root){
            inorder(root->left,s);
            s.insert(root->val);
            inorder(root->right,s); 
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        inorder(root,s);
        if(root==NULL)
            return NULL;
        if(s.size()==1)
            return -1;
        auto x=s.begin();
        x++;
        return *x;
    }*/
};
