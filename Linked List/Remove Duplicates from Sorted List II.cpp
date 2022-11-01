/*	82. Remove Duplicates from Sorted List II
	Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers 
	from the original list. Return the linked list sorted as well.
		Input: head = [1,2,3,3,4,4,5]
		Output: [1,2,5]
	
	time complexity: O(n)
	space complexity: O(1)	
*/

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
        return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    while(cur->next && cur->next->next) {
        if(cur->next->val==cur->next->next->val) {
            int d = cur->next->val;
            while(cur->next && cur->next->val==d) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
        }
        else
            cur = cur->next; 
    }
    return dummy->next;
}
