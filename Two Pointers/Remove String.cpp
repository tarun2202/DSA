/*	Remove String
	Given two strings string1 and string2, remove those characters from first string(string1) which are present in 
	second string(string2). Both the strings are different and contain only lowercase characters.
	NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).
		
		Input: string1 = "computer",	string2 = "cat"
		Output: "ompuer"
		
	Time Complexity:O( |String1| + |String2| )
	Auxiliary Space: O(K),Where K = Constant   	
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	char s1[100];
	char s2[100];
	cin>>s1>>s2;
	
	int arr[26]={0};	//array to count the frequency of charaters
	int l1=strlen(s1);
	int l2=strlen(s2);
	for(int i=0;i<l2;i++)	//flagging with -1, all index of characters which are present in 2nd string
		arr[s2[i]-'a']=-1;
	int j=0;	
	for(int i=0; i<l1; i++){	
		if(arr[s1[i]-'a']!=-1)	//stroring only those characters of string 1 whose index is not marked with -1.
			s1[j++]=s1[i];
	}
	s1[j]='\0';	//marking the last charcter as null to point to the end of the string.
	cout<<s1;
}
