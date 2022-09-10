/*	H-Index II
	Given an array of integers citations where citations[i] is the number of citations a researcher received
	for their ith paper, and citations is sorted in an ascending order, return compute the researcher's 
	h-index.
	According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers 
	have at least h citations each, and the other n - h papers have no more than h citations each.
	If there are several possible values for h, the maximum one is taken as the h-index.
		Input: citations = [3,0,6,1,5]
		Output: 3
	time complexity: O(logn)
	space coplexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int findHIndex(vector<int>& citations) {
    int len = citations.size();
    int left=0, right= len-1,  mid;
    int ans=0;
    while(left<=right){
        mid=left+ (right-left)/2;
        if(citations[mid] <= (len-mid)){
            left = mid + 1;
            ans=max(ans,citations[mid]);
        }
        else{
            right = mid - 1;
            ans=max(ans,len-mid);
        } 
    }
    return ans;
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
