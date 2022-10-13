/*	Queue implemented using stack.
	Time complexity: push operation- O(1)
					 pop operation- O(1)
					 top operation- O(1)
					 size operation- O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
class MyQueue{
	public:
	stack<int>s1,s2;
	int front, bottomOfS2;
	MyQueue(){
		front=-1;
		bottomOfS2=-1;
	}
	void push(int x){
		if(s1.empty() && s2.empty())
			front=x;
		else if(s1.empty())
			bottomOfS2=x;

		s1.push(x);	
        cout<<"element pushed is: "<<x<<endl;;	
	}
	int pop(){
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		int popped=s2.top();
		s2.pop();
		if(!s2.empty())
			front=s2.top();
		else if(!s1.empty())
			front=bottomOfS2;
		return popped;		
	}
	int peek(){
		return front;
	}
	bool empty(){
		return (s1.empty() && s2.empty());
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

