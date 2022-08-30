#include<bits/stdc++.h>
using namespace std;
void printParentheses(int n,int l,int r,int i,char arr[]){
	//termination condition, filled up all the position
	if(i==2*n){
		//printing the whole string consist of n valid parentheses pair combination
		for(i=0;i<2*n;i++)
			cout<<arr[i];
		cout<<endl;	
		return;
	}
	//count of '(' equal to count of ')'
	if(l==r){
		arr[i]='(';
		printParentheses(n,l+1,r,i+1,arr);
	}
	//count of '(' gretaer than count of ')'
	else if(l>r){
		//checking if all '(' exhausted or not
		if(l==n){ //if exhausted
			arr[i]=')';
			printParentheses(n,l,r+1,i+1,arr);
		}
		else{ //if not exhausted
			arr[i]='(';
			printParentheses(n,l+1,r,i+1,arr);
			arr[i]=')';
			printParentheses(n,l,r+1,i+1,arr);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int idx=0,l=0,r=0;
	char arr[2*n];
	printParentheses(n,l,r,idx,arr);	
}
