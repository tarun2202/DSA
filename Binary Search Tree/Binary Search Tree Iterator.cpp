/*	173. Binary Search Tree Iterator
	Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree:
	BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part 
	of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the 
	BST.
	boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise 
	returns false.
	int next() Moves the pointer to the right, then returns the number at the pointer.
*/

// method 1:  
/*  TC: BSTIterator--> O(H)
		next()--> O(1)
		hasNext()--> O(1)
	SC: O(N) for using inorder vector.
*/		
class BSTIterator {
public:
	// method 1:
    /*vector<int>inorder;
    int c=0;
    void traverse(TreeNode *root){
        if(!root)
            return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        return inorder[c++];
    }
    
    bool hasNext() {
        return c<inorder.size();
    }*/
    
    //method 2:
    stack<TreeNode*>stk;
    BSTIterator(TreeNode* root) {
        TreeNode *node=root;
        while(node){
            stk.push(node);
            node=node->left;
        }
    }
    
    int next() {
        TreeNode *ans=stk.top();
        stk.pop();
        TreeNode *node=ans->right;
        while(node){
            stk.push(node);
            node=node->left;
        }
        return ans->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
