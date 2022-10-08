/*Reverse a Stack: 
	method 1: Iteratively   TC: O(3n)	SC: O(2n)
	Method 2: Recursion		TC: O(n^2)	SC: O(n)
*/	

#include <bits/stdc++.h>
using namespace std;
//method 1: iteratively
/*stack<int> reverseStack(stack<int> stk){
    stack<int>aux1;
    stack<int>aux2;
    while(!stk.empty()){
        aux1.push(stk.top());
        stk.pop();
    }
    while(!aux1.empty()){
        aux2.push(aux1.top());
        aux1.pop();
    }
    while(!aux2.empty()){
        stk.push(aux2.top());
        aux2.pop();
    }
    return stk;
}*/

//method 2: Recursively
void pushBottom(int x, stack<int>&stk){
	if(stk.empty()){
		stk.push(x);
		return;
	}
	int y=stk.top();
	stk.pop();
	pushBottom(x,stk);
	stk.push(y);
}
stack<int> reverseStack(stack<int> stk){
	if(stk.empty()){
		return stk;
	}	
	int y=stk.top();
	stk.pop();
	reverseStack(stk);
	pushBottom(y, stk);
}

int main() {
    int n;
	cin>>n;
	stack<int>stk;
	for(int i=0;i<n;i++){
        int val;
        cin>>val;
        stk.push(val);
    }
    stack<int>temp = reverseStack(stk);
    vector<int>ans;
    while(!temp.empty()){
        ans.push_back(temp.top());
        temp.pop();
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
}

