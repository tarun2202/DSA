/*	Minimum element in BST
	Given a Binary Search Tree. The task is to find the minimum element in this given BST.
		Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
	Output: 1
	
	time complexity: O(H)
	space complexity: O(1)
*/

int minValue(Node* root) {
    if(root==NULL)
        return -1;
    Node *curr=root;
    while(curr->left!=NULL)
        curr=curr->left;
    return curr->data;    
}
