/*	Allocate the Books
	Given an array of integers A of size N and an integer B. The College library has N bags, the ith book 
	has A[i] number of pages. You have to allocate books to B number of students so that the maximum 
	number of pages allocated to a student is minimum.
	conditions: ->each student must get atleast 1 book.
				->all the books should be allocated.
				->allotment must be contiguous.
	N=4, B=2, A={12, 34, 67, 90}
	output: 113
	
	time complexity: O(nlog(right-left))
	space complexity: O(!)			
*/

#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&pages,int s,int mid){
	int n=pages.size();
	//initially starts with 1st student
	int cnt=1,sum=0;
	for(int i=0;i<n;i++){
		//allocate pages till sum<mid, when sum>mid, starts allocating pages to next student
		if(sum+pages[i]>mid){
			cnt++;
			sum=pages[i];
		}
		else{
			sum+=pages[i];
		}
	}
	//checking if the count of students after allocating all pages is equal to original student count, if yes
	//return true, else false;
	return cnt<=s;
}
int allocateBooks(vector<int>&pages,int n,int s){
	//edge case: when number of student is more than the no. of books available which violates cond. 1
	if(s>n)
		return -1;
	//min val: maximum number in pages[], when M==N, then the max. pages book allocated to 1 student is max 
	//value lement in pages[] array	
	int left=INT_MIN;
	for(int i=0;i<n;i++)
		left=max(left,pages[i]);
	//when only 1 student is there, then the all pages are allocated to him only--> sum of pages[] array 
	int right=0;
	for(int i=0;i<n;i++)
		right+=pages[i];
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		//when lies on the left part, when upperbound vale of mid is not valid, move to right
		if(!isPossible(pages,s,mid))
			left=mid+1;
		else{
			//when I'm there at answe, to validate, inspect mid-1, if return false, then mid is my answer.
			if(!isPossible(pages,s,mid-1))
				return mid;
			//answer lies in left, move right=mid-1; 
			else
				right=mid-1;
		}	
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>pages(n);
	for(int i=0;i<n;i++)
		cin>>pages[i];
	int stu;
	cin>>stu;
	int ans=allocateBooks(pages,n,stu);
	cout<<ans;	
}
