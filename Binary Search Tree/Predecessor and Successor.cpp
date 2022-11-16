/*	Predecessor and Successor
	There is BST given with root node with key part as an integer only. You need to find the in-order successor and 
	predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
		input:
		output: 
		
	naive approach-->     TC: O(N)	SC: O(N)
	better appraoch--> 	  TC: O(N)	SC: O(1)
	optimised appraoch--> TC: O(H)	SC: O(1)	

*/

// method 1: naive approach
void inorderTraversal(Node *root, vector<Node*> &inorder){
    if(!root)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root);
    inorderTraversal(root->right, inorder);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre=NULL;
    suc=NULL;
    vector<Node*>inorder;
    inorderTraversal(root,inorder);
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]->key > key){
            suc=inorder[i];
            break;
        }
    }
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]->key < key){
            pre=inorder[i];
        }
    }
}

// method 2: better approach
/*void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // If root is null return
    if(!root)
        return ;
         
    // traverse the left subtree   
    findPreSuc(root->left, pre, suc, key);
     
    // root data is greater than key
    if( root->key > key){
        // suc stores the node whose data is greater than key and is smaller than 
        //the previously stored data in suc which is successor
        if(!suc || suc && suc->key > root->key)
            suc = root;
    }
     
    // if the root data is smaller than key store it in pre which is predecessor
    else if( root->key < key){
        pre = root;
    }
     
    // traverse the right subtree
    findPreSuc(root->right, pre, suc, key);
}*/

// method 3: optimised approach
/*void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre=NULL;
    suc=NULL;
    // finding successor
    Node *node = root;
    while(node){
        if(node->key>key){
            suc= node ;
            node = node->left;
        }
        else{
            node = node->right ;
        }
    }
    // finding predecessor
    node = root;
    while(node!= NULL){
        if(node->key<key){
            pre= node ;
            node = node->right;
        }
        else{
            node = node->left ;
        }
    }
}*/
