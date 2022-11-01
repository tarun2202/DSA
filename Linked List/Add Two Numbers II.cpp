/*	445. Add Two Numbers II
	You are given two non-empty linked lists representing two non-negative integers. The most significant digit 
	comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked 
	list.
		Input: l1 = [7,2,4,3], l2 = [5,6,4]
		Output: [7,8,0,7]
	
	time complexity: O(m+n)
	space complexity: O(m+n)
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {       
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->val);
        l1=l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->val);
        l2=l2->next;
    }
    int carry=0;
    ListNode* result=NULL;
    while(s1.empty()==false || s2.empty()==false){
        int a=0,b=0;
        if(s1.empty()==false){
            a=s1.top();
            s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();
            s2.pop();
        }
        int total=a+b+carry;
        ListNode* temp=new ListNode(total%10);
        carry=total/10;
        if(result==NULL)
            result=temp;
        else{
            temp->next=result;
            result=temp;
        }
    }
    if(carry!=0){
        ListNode* temp=new ListNode(carry);
        temp->next=result;
        result=temp;
    }
    return result;
}
