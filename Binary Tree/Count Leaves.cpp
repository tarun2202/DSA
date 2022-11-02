/*	Count Leaves in Binary Tree
	Given a Binary Tree of size N , You have to count leaves in it.
		Input:
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
		Output: 3
	
	time complexity: O(n)
	space complexity: O(h) where h: height of tree
*/

int countLeaves(Node* root) {
    if(root==NULL)
        return 0;
    if(root->left==NULL and root->right==NULL)
        return 1;
    return countLeaves(root->left)+countLeaves(root->right);    
}
