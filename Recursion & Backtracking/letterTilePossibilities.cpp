/*	1079. Letter Tile Possibilities
	You have n  tiles, where each tile has one letter tiles[i] printed on it.
	Return the number of possible non-empty sequences of letters you can make using the letters printed 
	on those tiles.
	
	Input: tiles = "AAB"
	Output: 8
	Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
*/

#include<bits/stdc++.h>
using namespace std;
int ans=0;
void countSeq(string &s,int i){
	int n=s.length();
	if(i>n)
		return;
	ans++;	
	int freq[26]={0};
	for(int j=i;j<n;j++)	{
		if(freq[s[j]-'A']==0){
			swap(s[i],s[j]);
			countSeq(s,i+1);
			swap(s[i],s[j]);
			freq[s[j]-'A']++;	
		}	
	}
}
int main(){
	string s;
	cin>>s;
	countSeq(s,0);
	cout<<ans-1;
}
