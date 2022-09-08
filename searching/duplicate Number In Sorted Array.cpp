#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector < int > & arr) {
	int n = arr.size();
    int s=0,e=n-1;
    int mid;
    while(s<=e){
    mid=(s+e)/2;
  	    if(arr[mid]==mid) //belogs to 2nd part 
  		    e=mid-1;
  	    else{	//belongs to 1st part
	  	    if(arr[mid+1]==mid){ 
			  	//if current element is same as immediate right neighbor, return arr[mid], as duplicate no.
	  	    	if(arr[mid]==arr[mid+1])
	  	    		return arr[mid];
			}
		    else
			    s=mid+1;	  	
  	    }
    }
}
int main() {
	int n;
	cin>>n;
  	vector < int > arr(n);
  	for(int i=0;i<n;i++)
  		cin>>arr[i];
  	int ans=findDuplicate(arr);
	cout<<ans;  	
}
