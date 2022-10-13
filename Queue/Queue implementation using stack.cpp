/*	Queue implemented using stack.
	Time complexity: push operation- O(1)
					 pop operation- O(n)
					 top operation- O(1)
					 size operation- O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    public: 
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        cout<<"element pushed is: "<<x<<endl;
    }
    
    int pop() {
        int popped;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        popped=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        int peekElement;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        peekElement=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return peekElement;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){
	MyQueue q;
	q.push(1);
	q.push(2);
	cout<<"peek element is: "<<q.peek()<<endl;
	cout<<"element pooped is: "<<q.pop()<<endl;
	cout<<"is queue empty (1--> empty, 0--> non-empty): "<<q.empty()<<endl;
}
