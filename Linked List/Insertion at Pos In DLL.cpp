/*	Doubly linked list Insertion at given position
	Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the 
	position just after pth node in the doubly linked list.
		Input: LinkedList: 2<->4<->5	p = 2, x = 6 
		Output: 2<->4<->5<->6
	
	time complexity: O(n)
	space complexity: O(1)	
*/

void addNode(Node *head, int pos, int data)
{
    Node *d=new Node(data);
    Node *temp=head;
    Node *size=head;
    int count=0;
    while(size!=NULL) {
        count++;
        size=size->next;
    }
    if(count==pos+1) {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=d;
        d->prev=temp;
    }
    else {
        for(int i=0; i<pos; i++)
            temp=temp->next;
        Node *curr=temp->next;
        temp->next=d;
        d->next=curr;
        curr->prev=d;
        d->prev=temp;
    }
}
