/*	Generate Binary Numbers
	Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.
		Input:N = 5
		Output: 1 10 11 100 101
		Explanation: Binary numbers from 1 to 5 are 1 , 10 , 11 , 100 and 101.
	
	naive approach    --> TC: O(nlogn)	SC: O(1)
	optimised approach--> TC: O()	SC: O()	
*/

#include<bits/stdc++.h>
using namespace std;

// Brute Force approach- 
/*void printBinary(int n){
	int bin_num[1000];
	int i = 0;
	while (n > 0) {
		bin_num[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << bin_num[j];
}

void generateBinaryEquivalent(int n){
	for(int i=1;i<=n;i++){
		printBinary(i);
		cout<<" ";
	}
}*/

// optimised approach-
void generateBinaryEquivalent(int n){
	queue<long long>q;
	q.push(1);
	while(n--){
		long long x=q.front();
		q.pop();
		cout<<x<<" ";
		q.push(10*x);
		q.push(10*x+1);
	}
}

/* GFG Question Template
vector<string> generate(int N){
	queue<string>q;
	vector<string>res;
	q.push("1");
	while(N--){
	    string s1=q.front();
	    q.pop();
	    res.push_back(s1);
	    string s2=s1;
	    q.push(s1.append("0"));
	    q.push(s2.append("1"));
	}
	return res;
}
*/

int main(){
	int n;
	cin>>n;
	generateBinaryEquivalent(n);
}
