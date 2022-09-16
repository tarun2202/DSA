/*	973. K Closest Points to Origin
	Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer
	k, return the k closest points to the origin (0, 0).
	
		Input: points = [[3,3],[5,-1],[-2,4]], k = 2
		Output: [[3,3],[-2,4]]
	
	time complexity: O(nlogn)
	space complexity: O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
//custom comparator
bool compare(pair<int,int> p1, pair<int,int> p2){
	int d1=p1.first*p1.first + p1.second*p1.second;
	int d2=p2.first*p2.first + p2.second*p2.second;
	return d1<d2;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int> > vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
	sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<k;i++)
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
}

