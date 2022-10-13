/*	Implement Stack using single queue- 
	
	time complexity: push operation- O(1)
					 pop operation - O(1)
					 top operation - O(1)
					 size operation- O(1)
					 empty operation-O(1)
	
	space complexity: O(N)				 
*/

#include<bits/stdc++.h>
using namespace std;
class MyStack{
    queue<int>q;
    public:
    	
    void push(int data){
    	int s=q.size();
    	q.push(data);
    	cout<<"element pushed is: "<<data<<endl;
    	for(int i=0;i<s;i++){
    		q.push(q.front());
    		q.pop();
		} 
    }
    
    int pop(){
        if(q.empty()){
        	cout<<"underflow!!!"<<endl;
        	exit(0);
		}
    	else{
    		int popped=q.front();
    		q.pop();
            return popped;
		}
    }
    int top(){
        return (q.empty())? -1: q.front();
    } 
    
    int size(){
        return q.size();
    }
    bool empty(){
        return q.empty();
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
