/*	114. Flatten Binary Tree to Linked List
	Given the root of a binary tree, flatten the tree into a "linked list":
	-> The "linked list" should use the same TreeNode class where the right child pointer points to the next node in 
	   the list and the left child pointer is always null.
	-> The "linked list" should be in the same order as a pre-order traversal of the binary tree.
	Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
	Output:	1->2->3->4->5->6
	
	using recursion: TC: O(n)
					 SC: O(h)
	using morris traversal: TC: O(n)
							SC: O(1)				  
*/

class Solution {
public:
    TreeNode * prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        flatten(root -> right);
        flatten(root -> left);

        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};


