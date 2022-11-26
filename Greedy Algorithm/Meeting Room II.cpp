/*	Meeting Room II
	We have been given ‘N’ activities. The start time and end time of all activities are given by two arrays start[N] 
	and end[N]. Find the maximum number of activities that can be performed with a constraint that two activities 
	can be performed at a time.
		Input: start [ ] ={1,6,3,15,10}  end [ ] ={4,9,12,20,25}
		Output: 5
		
	time complexity: O(nlogn)
	space complexity: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&p1, pair<int, int>&p2) {
	return p1.second < p2.second;
}
 
int main() {
	int n;
	cin>>n;
    vector<int>st(n);
    vector<int>end(n);
    for(int i=0;i<n;i++){
		int val1;
	    cin>>val1;
	    st.push_back(val1);
    }
    for(int i =0;i <n;i++){
		int val2;
		cin>>val2;
        end.push_back(val2);
	}
    vector<pair<int,int> >ans(n);
    for(int i=0;i<n;i++)
	    ans.push_back({st[i], end[i]});
    sort(ans.begin(), ans.end(), cmp);
    
    int res=0;
    int e1=0;
    int e2=0;
    for(int i=0;i<n;i++){
	   	pair<int,int>p = ans[i];
       //handling case of both activity can be assigned
	    if(p.first > e1 and p.first > e2){
			int maxii= max(e1, e2);
			res++;
			if(maxii==e1)
				e1=p.second;
			else
				e2=p.second;
	    }  
		//no catergory can be asigned, reviewing this case
	    else if(p.first < e1 and p.first <e2 )
		    continue;
	    else{   
			//cases of one can be assinged and other can not be assigned
			res++;
			if( p.first > e1 and p.first < e2)
				e1=p.second;
			else
				e2=p.second;
     	}
   	}
	cout<<res;
	return 0;
}
