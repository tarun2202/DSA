/*	Level Order Traversal
	given a positive integer n. print first n natural numbers whose digits are {1,2,3}. print in sorted form.
		input: N=10
		output: 1, 2, 3, 11, 12, 13, 21, 22, 23, 31
	
	Time Complexity: O(N)
	space complexity: O(3N)~ O(N)
*/

#include<bits/stdc++.h>
using namespace std;
void findFirstSeries(int n){
	int cnt=0;
	queue<int>q;
	q.push(0);
	while(cnt<n){
		int x=q.front();
		if(x!=0){
			cout<<x<<" ";
			cnt++;
		}	
		q.pop();
		q.push(x*10+1);
		q.push(x*10+2);
		q.push(x*10+3);
	}
}
int main(){
	int n;
	cin>>n;
	findFirstSeries(n);
}
