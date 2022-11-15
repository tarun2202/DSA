/*	Construct BST from Postorder
	Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The 
	output will be inorder traversal of the constructed BST.
		Input: 1 7 5 50 40 10
		Output: 1 5 7 10 40 50
	
	time complexity: O(N^2)
	space complexity: O(h)	
*/

Node *makeBST(int post[], int i, int j){
    if(i>j)
        return NULL;
    Node *root= new Node(post[j]);    
    if(i==j)
        return root;
    int idx=i;
    while(post[idx]<root->data)
        idx++;
    root->left=makeBST(post,i,idx-1);
    root->right=makeBST(post,idx, j-1);
    return root;
}
Node *constructTree (int post[], int size) {
    if(size==0)
        return NULL;
    return makeBST(post,0,size-1);    
}
