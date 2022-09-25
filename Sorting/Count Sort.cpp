/*	Count Sort-
	time complexity : 0(n);
    space complexity:  0(max-min+1)
*/

#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&x){
    int large=*max_element(x.begin(),x.end());
    int small=*min_element(x.begin(),x.end());
	
	//making frequency array-
    vector<int>freq(large-small+1,0);
    for(int i=0;i<x.size();i++){
        freq[x[i]-small]++;
    }
    vector<int>ans(x.size(),0);
    
    //cummulative frequency array: prefix sum of frequency
	for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }
    //iterate over the original array
    for(int i=0;i<x.size();i++){
      ans[freq[x[i]-small]-1]=x[i];
      freq[x[i]-small]--;    
    }
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    solve(v);
}
