/*	Given a string and a character. remove all the occurences of given character from the string. 
		input: s="computer", ch='c'
		output: "omputer"
	
	time complexity: O(n)
	space complexity: O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
void removeCharacter(char s[],char c){
    int len=strlen(s);
	int i,j=0;
	for(i=0,j=0;i<len;i++)
		if(s[i]!=c)
			s[j++]=s[i];
	
	s[j]='\0';
}
int main(){
	char s[100];
	cin>>s;
	char ch;
	cin>>ch;
    removeCharacter(s,ch);
    cout<<s;
}

