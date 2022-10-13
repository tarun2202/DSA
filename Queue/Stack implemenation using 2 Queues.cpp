/*	Implement Stack using queue (2 queues)-
	
	time complexity: push operation- O(1)
					 pop operation - O(1)
					 top operation - O(1)
					 size operation- O(1)
					 empty operation-O(1)
	
	space complexity: O(2N)				 
*/

#include<bits/stdc++.h>
using namespace std;
class MyStack{
    queue<int> q1,q2;
    public:
    void push(int data){
        q1.push(data);
        cout<<"element pushed is: "<<data<<endl;
    }
    int pop(){
        if(q1.empty())
            return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }    
        int popped=q1.front();
        q1.pop();
        queue<int>q=q1;
        q1=q2;
        q2=q;
        return popped;
    }
    int top(){
        if(q1.empty())
            return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }    
        int peekElement=q1.front();
        q2.push(peekElement);
        q1.pop();
        queue<int>q=q1;
        q1=q2;
        q2=q;
        return peekElement;
    }
    int size(){
        return q1.size();
    }
    bool empty(){
        return q1.empty();
    }
};
int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "current size: " << st.size() <<endl;
    cout << "peek element is: "<<st.top() <<endl;
    cout<<"element popped is: "<<st.pop() <<endl;
    cout << "peek element is: "<<st.top() <<endl;
    cout<<"element popped is: "<<st.pop() <<endl;
    cout << "peek element is: "<<st.top() <<endl;
    cout << "current size: " << st.size() <<endl;
    cout<<"element popped is: "<<st.pop() <<endl;
    cout<<"element popped is: "<<st.pop() <<endl;
}
