/*	Remove duplicates from an unsorted linked list
	Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
	When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are 
	to be removed.
		Input: head = 12->11->12->21->41->43->21 
		Output: 12->11->21->41->43. 
		
	naive approach   --> TC: O(n^2)		SC: O(1)
	better approach  --> TC: O(nlogn)	SC: O(1)
	optimsed approach--> TC: O(n)	    SC: O(n)	
*/

//naive appraoch
Node * removeDuplicates( Node *head) {
	if(head==NULL)
		return head;
	Node *ptr1, *ptr2;
	ptr1=head;
	while(ptr1!=NULL and ptr1->next!=NULL){
		ptr2=ptr1;
		while(ptr2->next!=NULL){
			if(ptr2->data==ptr2->next->data){
				Node *dup=ptr2->next;
				ptr2->next=ptr->next->next;
				delete dup;
			}
			else
				ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}		
	return head;
}

//optimised approach
Node * removeDuplicates( Node *head) {
    unordered_map<int,int>seen;
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        if(seen.find(curr->data)!=seen.end()){
            Node *temp=curr;
            prev->next=curr->next;
            delete temp;
        }
        else{
            seen[curr->data]++;
            prev=curr;
        }
        curr=curr->next;
    }
    return head;
}
