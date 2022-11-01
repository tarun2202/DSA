/*	2. Add Two Numbers
	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse 
	order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
		Input: l1 = [2,4,3], l2 = [5,6,4]
		Output: [7,0,8]
		Explanation: 342 + 465 = 807.
		
	time complexity: O(max(m,n))
	space complexity: O(max(m,n)+1)		where, m and n are the respective length of list 1 and list2.	
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy=new ListNode(); // dummy->next: points to the head of the output list 
    ListNode *temp=dummy; //used to track the current node in the output list
    int carry=0;
    //until either of list1, list2 or carry is true 
    while(l1!=NULL || l2!=NULL || carry){   
        int sum=0;
        // adding the list node->val one by one
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        // putting the result of digit by digit addition into the output list
        ListNode *node=new ListNode(sum%10); 
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next; //returning the head of output list
}
