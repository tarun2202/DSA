/* GFG: Count Total Nodes
	Given the root of a complete binary tree, return the number of the nodes in the tree.
		Input: root = [1,2,3,4,5,6]
		Output: 6
	
	time complexity: O(n)
	space complexity: O(h)	
*/	

int countNodes(Node *root){
	if(root==NULL)
		return 0;
	return 1+countNodes(root->left)+countNodes(root->right);	
}  

