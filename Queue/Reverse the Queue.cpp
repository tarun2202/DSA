/*	Reverse A Queue.
	Iterative approach--> TC: O(n)		SC: O(n)
	Recursive Approach--> TC: O(n)		SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// approach 1: Iterative approach
void reverseQueue(queue<int>&q){
	stack<int>aux;
	while(!q.empty()){
		aux.push(q.front());
		q.pop();
	}
	while(!aux.empty()){
		q.push(aux.top());
		aux.pop();
	}
}

//approach 2: recursive Approach
/*void reverseQueue(queue<int>&q){
	if(q.empty())
		return;
	int data=q.front();
	q.pop();
	reverseQueue(q);
	q.push(data);	
}*/

int main(){
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	reverseQueue(q);
	cout<<"reversed queue is..."<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}
