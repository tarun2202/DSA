/*	GFG: Flattening a Linked List
	Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
	(i) a next pointer to the next node,
	(ii) a bottom pointer to a linked list where this node is head.
	Each of the sub-linked-list is in sorted order.
	Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
		Input: 5 -> 10 -> 19 -> 28
			   |     |     |     | 
			   7     20    22   35
			   |           |     | 
			   8          50    40
			   |                 | 
			   30               45
		Output:  5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50.	
		
	time complexity: O(n)
	space complexity: O(1)	
*/

Node *mergeTwoList(Node *a, Node *b){
    Node *temp=new Node(0);
    Node *res=temp;
    // merging the list by comparing the node->data of the two lists.
    while(a!=NULL and b!=NULL){
        if(a->data<=b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    // merge the remaining nodes of either of the lists that left.
    if(a!=NULL)    temp->bottom=a;
    else            temp->bottom=b;
    // returning the head of the two merged lists
    return res->bottom;
}
Node *flatten(Node *root) {
    if(root==NULL or root->next==NULL)
        return root;
    //recur to the right of the list    
    root->next=flatten(root->next);
    // now merge the two list from last
    root=mergeTwoList(root, root->next);
    // returning the head of the flatten list
    return root;
}
