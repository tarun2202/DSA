/*	Queue implemented using array.
	Time complexity: push operation- O(1)
					 pop operation- O(1)
					 top operation- O(1)
					 size operation- O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
class Queue{
	int *arr;
	int front, rear, currSize, maxSize;
	public:
	Queue(){
		arr=new int[100];
		front=-1;
		rear=-1;
		currSize=0;
	}
	Queue(int maxSize){
		(*this).maxSize=maxSize;
		arr=new int[maxSize];
		front=-1;
		rear=-1;
		currSize=0;
	}
	void push(int newElement){
		if(currSize==maxSize){
			cout<<"Overflow!!!"<<endl;
			exit(0);
		}
		if(rear==-1){
			front=0; rear=0;
		}
		else	rear=(rear+1)%maxSize;
		arr[rear]=newElement;
		cout<<"pushed element is: "<<newElement<<endl;
		currSize++;
	}
	int pop(){
		if(currSize==0){
			cout<<"underflow!!!"<<endl;
			exit(0);
		}
		int popped=arr[front];
		if(currSize==1){
			front=-1; rear=-1;
		}
		else	front=(front+1)%maxSize;
		currSize--;
		return popped;
	}
	int size(){
		return currSize;
	}
	int top(){
		if(currSize==0){
			cout<<"queue is empty!"<<endl;
			exit(0);
		}
		return arr[front];
	}
	void print(){
		for(int i=front;i<=rear;i++)
			cout<<arr[i%maxSize]<<" ";
		cout<<endl;		
	}
};
int main(){
	Queue q(6);
	q.push(4);
	q.push(14);
	q.push(24);
	q.push(34);
	cout<<"peek element before deleting  :"<<q.top()<<endl;
	cout<<"size of queue before deleting :"<<q.size()<<endl;
	cout<<"1st element to be deleted     :"<<q.pop()<<endl;
	cout<<"peek of queue after deleting  :"<<q.top()<<endl;
	cout<<"size of queue after deleting  :"<<q.size()<<endl;
	q.print();
}
