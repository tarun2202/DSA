/*	99. Recover Binary Search Tree
	You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were 
	swapped by mistake. Recover the tree without changing its structure.
		Input: root = [1,3,null,null,2]
		Output: [3,1,null,null,2]
		Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
	
	time complexity:
	space complexity:	
*/

class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>&nodes){
        if(!root) 
            return;
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>nodes;
        //doing inorder traversalof given bst to get node in sorted order. 
        //at max two points where current node val < than previous node. 
        inorder(root, nodes);
        TreeNode *n1=NULL, *n2=NULL, *n3=NULL;
        int count=0;
        for(int i=0;i<nodes.size()-1;i++){
            if(nodes[i]->val>nodes[i+1]->val){
                //1st point where current node val is smaller than previous node 
                if(count==0){
                    count=1;
                    n1=nodes[i];
                    n2=nodes[i+1];
                }
                //2nd point where current node val is samller than previous node
                else{
                    count=2;
                    n2=nodes[i+1];
                    break;
                }
            }
        }
        // swapping the nodes
        int temp=n1->val;
        n1->val=n2->val;
        n2->val=temp;
    }
};
