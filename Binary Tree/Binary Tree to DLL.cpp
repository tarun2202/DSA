/*	Binary Tree to DLL
	Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes 
	are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be 
	same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the 
	head node of the DLL.
	Input:
       10
      /   \
     20   30
   /   \
  40   60
	Output: 40 20 60 10 30 
			30 10 60 20 40
	Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
*/

class Solution
{
    public: 
    pair<Node*, Node*>convert(Node *root){
        //base case- 
		if(root==NULL)
            return {NULL,NULL};
            
        pair<Node*,Node*>lst=convert(root->left);
        pair<Node*,Node*>rst=convert(root->right);
        Node* head=root;	//when rst is null
        Node* tail=root;	//when lst is null
        // above also works when at leaf: return both head and tail as NULL.
        
		root->left=lst.second;	// root is connected to tail of lst
        if(lst.second){	//when right of lst is non-NULL
            lst.second->right=root;
            head=lst.first;
        }
        root->right=rst.first;	//root is connected to head of rst
        if(rst.first){	//when left of rst is non-NULL
            rst.first->left=root;
            tail=rst.second;
        }
        return {head,tail};	//returning the head and tail of formed DLL
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root) {
        pair<Node*,Node*>res=convert(root);
        return res.first;
    }
};
