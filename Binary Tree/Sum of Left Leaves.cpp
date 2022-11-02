/*	404. Sum of Left Leaves
	Given the root of a binary tree, return the sum of all left leaves.
	Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
	Output: 13
	
	time complexity: O(n)
	space complexity: O(h)
*/

class Solution {
public:
    // checking if the node is leaf or not.
    bool isLeaf(TreeNode *node){
        if(node == NULL)
            return false;
        if(node->left==NULL and node->right==NULL)
            return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        if(root!=NULL){
            //check if node is leaf or not, if yes then add the left node value to sum
            if(isLeaf(root->left))
                res += root->left->val;
            else
                // recur for left child of root
                res += sumOfLeftLeaves(root->left);
            //recur for the right child of root
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }
};

/*class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};*/
