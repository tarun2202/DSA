/*	83. Remove Duplicates from Sorted List
	Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return 
	the linked list sorted as well.
		Input: head = [1,1,2,3,3]
		Output: [1,2,3]
	
	time complexity: O(n)
	space complexity: O(1)	
*/

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
        return NULL;
    ListNode *curr=head;
    while(curr->next!=NULL){
        if(curr->val == curr->next->val){
            ListNode *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else curr=curr->next;
    }
    return head;
}
