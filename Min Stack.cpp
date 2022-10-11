#include<bits/stdc++.h>
using namespace std;
class Solution{
    stack<pair<int,int>> st;
    public:
       int getMin(){
           if(st.empty()) return -1;
           return st.top().second;
       }

       int pop(){
           if(st.empty()) return -1;
           int t = st.top().first;
           st.pop();
           return t;
       }
       
       void push(int x){
           if(st.empty()) {
               st.push({x,x});
               return;
           }
           int mn = st.top().second;
           st.push({x,min(mn,x)});
       }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>q;
		Solution ob;
		while(q--){
			int qt;
			cin>>qt;
			if(qt==1){
				//push
				int att;
				cin>>att;
				ob.push(att);
			}
			else if(qt==2){
				//pop
				cout<<ob.pop()<<" ";
			}
			else if(qt==3){
				//getMin
				cout<<ob.getMin()<<" ";
			}
		}
		cout<<endl;	
	}
}
