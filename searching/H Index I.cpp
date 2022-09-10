/*	H-Index
	Given an array of integers citations where citations[i] is the number of citations a researcher received
	for their ith paper, return compute the researcher's h-index.
	According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers 
	have at least h citations each, and the other n - h papers have no more than h citations each.
	If there are several possible values for h, the maximum one is taken as the h-index.
		Input: citations = [3,0,6,1,5]
		Output: 3
	time complexity: O(nlogn + n) ~ o(nlogn)
	space coplexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int findHIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size(), i;
    for(i = 1; i <= n; i++)
        if(citations[n-i] < i) 
			break;
        return i-1;
}
int main(){
	int n;
	cin>>n;
	vector<int>citation(n);
	for(int i=0;i<n;i++)
		cin>>citation[i];
	int ans=findHIndex(citation);
	cout<<ans;	
}
