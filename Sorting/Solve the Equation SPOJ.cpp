/*	Solve The Equation: 
	You are given a set S of integers between -30000 and 30000 (inclusive).
	Find the total number of sextuples  that satisfy: 
			(a*b+c) / d - e = f		where: d!=0
		
		time complexity: O(N^3.logN)
		space complexity: O(N^3)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std ;
ll lowind(ll val , vector<ll>&lhs){
    ll l = 0 ;
    ll h = lhs.size() - 1;
    while( l <= h){
        ll m = (h + l)/2;
    	if(lhs[m] == val){
        	if(lhs[m - 1] == val)
               h = m - 1;
           else
               return m ;
       }
       else{
           if(lhs[m] > val)
               h = m - 1;
           else
               l = m + 1;
       }
   }
   return -1;
}
ll upperind(ll val , vector<ll>&lhs){
    ll l = 0 ;
    ll h = lhs.size() - 1;
    while(l <= h){
        ll m = (h + l)/2;
        if(lhs[m] == val){
            if(lhs[m + 1] == val)
                l = m + 1;
            else
                return m ;
        }
        else{
            if(lhs[m] > val)
                h = m - 1;
            else
                l = m + 1;
        }
    }
    return -1;
}
int main(){
    ll n ;
    cin >> n ;
    vector<ll>vec(n);
    ll i;
    for(i = 0 ; i < n ; i++){
        cin>> vec[i];
    }
    vector<ll>lhs;
    vector<ll>rhs;
    for(ll a = 0 ; a < n ; a++){
        for(ll b = 0 ; b < n ; b++){
           for(ll c = 0 ; c < n ; c++){
                lhs.push_back((vec[a] * vec[b]) + vec[c]);
            }
        }
    }
    for(ll e = 0 ; e < n ; e++){
        for(ll f = 0 ; f < n ; f++){
            for(ll d = 0 ; d < n ; d++){
                if(vec[d] != 0)
                    rhs.push_back((vec[e] + vec[f]) * vec[d]);
            }
        }
    }
    ll count = 0 ;
    sort(lhs.begin() , lhs.end());
    for(i = 0 ; i < rhs.size() ; i++){
        ll left = lowind(rhs[i] , lhs);	//finding the first occurence
        if(left != -1){
            ll right = upperind(rhs[i] , lhs);	//finding the last occurence
            count += right - left + 1;	//adding frequency of current element of rhs array in count.
        }
        else
            continue;
    }
    cout << count << endl;
    return 0 ;
}
