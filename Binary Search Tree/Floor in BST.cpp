/*	Floor in BST
	Given a BST and a number X, find Floor of X.
	Note: Floor(X) is a number that is either equal to X or is immediately smaller than X.
		Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
		X = 6
		Output: 5
	
	time complexity: O(H)
	space complexity: O(H)
*/

int findFloor(Node *root, int input){
	if(root==NULL)
		return -1;
	int Floor=-1;
	while(root){
		if(root->data==input){
			Floor=root->data;
			return Floor;
		}
		if(root->data>input)
			root=root->left;
		else{
			Floor=root->data;
			root=root->right;
		}	
	}	
	return Floor;
}
