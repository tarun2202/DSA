/*	Construct Tree from Preorder Traversal
	Construct a binary tree of size N using two given arrays pre[] and preLN[]. Array pre[] represents preorder 
	traversal of a binary tree. Array preLN[] has only two possible values L and N. The value L in preLN[] indicates 
	that the corresponding node in Binary Tree is a leaf node and value N indicates that the corresponding node is a 
	non-leaf node.
	Note: Every node in the binary tree has either 0 or 2 children.
	
	Input : 
		N = 5
		pre[] = {10, 30, 20, 5, 15}
		preLN[] = {N, N, L, L, L}

	Output:
          10
        /    \
      30      15
     /  \     
   20    5
   
   time complexity: O(N)
   space complexity: O(N)    
*/

Node* builtTree(int pre[], char preLN[], int &index, int n){
    int i = index; // store the current value of index in pre[]
 
    // Base Case: All nodes are constructed
    if (i == n)
        return NULL;
 
    // Allocate memory for this node and increment index for
    // subsequent recursive calls
    Node *temp = new Node ( pre[i] );
    index++;
 
    // If this is an internal node, construct left and
    // right subtrees and link the subtrees
    if (preLN[i] == 'N') {
      temp->left  = builtTree(pre, preLN, index, n);
      temp->right = builtTree(pre, preLN, index, n);
    }
 
    return temp;
}
// function should return the root of the new binary tree formed
Node *constructTree(int n, int pre[], char preLN[])
{
    int index=0;
    return builtTree(pre, preLN, index, n);
}
