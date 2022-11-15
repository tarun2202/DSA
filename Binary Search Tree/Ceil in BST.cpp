/*	Ceil in BST
	Given a BST and a number X, find Ceil of X.
	Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
		Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
		X = 6
		Output: 7
		Explanation: We find 7 in BST, so ceil of 6 is 7.
	
	time complexity: O(H)
	space complexity: O(H)	
*/

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int Ceil=-1;
    while(root){
        if(input==root->data){
            Ceil= root->data;
            return Ceil;
        }
        if(input>root->data)
            root=root->right;
        else{
            Ceil=root->data;
            root=root->left;
        }
    }
    return Ceil;
}
