/*	108. Convert Sorted Array to Binary Search Tree
	Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced 
	binary search tree.
		Input: nums = [-10,-3,0,5,9]
		Output: [0,-3,9,-10,null,5]
		Explanation: [0,-10,5,null,-3,null,9] is also accepted:
	
	time complexity: O()
	space complexity: O()	
*/

class Solution {
public:
    TreeNode * makeBST(vector<int>&nums, int i, int j){
        if(i>j)
            return NULL;
        int mid=(i+j)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=makeBST(nums, i, mid-1);
        root->right=makeBST(nums, mid+1, j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        TreeNode *ans=makeBST(nums,0, nums.size()-1);
        return ans;
    }
};
