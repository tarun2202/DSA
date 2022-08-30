/*	60. Permutation Sequence

	The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
	By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
		"123"
		"132"
		"213"
		"231"
		"312"
		"321"
	Given n and k, return the kth permutation sequence.
	Input: n = 3, k = 3
	Output: "213"
	
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void rightRotate(string& s,int i,int j){
	char temp=s[j];
	while(j>i){
        s[j]=s[j-1];
        j--;
    }
    s[i]=temp;	
}
void leftRotate(string& s,int i,int j){
	char temp=s[i];
	while(i<j){
		s[i]=s[i+1];
		i++;
	}
	s[j]=temp;
}
void permute(string& s,int i){
	if(i==s.length()-1){
		ans.push_back(s);
		return;
	}
	for(int j=i;j<s.length();j++){
		rightRotate(s,i,j);
		permute(s,i+1);
		leftRotate(s,i,j);
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	string s;
	for(int i=1;i<=n;i++)
		s+=to_string(i);  //works fine in other ide.
	permute(s,0);
	cout<<ans[k-1];	
}


