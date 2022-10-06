/*	149. Max Points on a Line
	Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum 
	number of points that lie on the same straight line.
		Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
		Output: 4	
	Naive approach-->     TC: O(n^3)            SC: O(1)
    Optimised Approach--> TC: O(n^2.log(max))   SC:O(n)
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach--> accecpted on leetcode: as constraint on points value is- 0<=points[i]<=300
/*int maxPoints(vector<vector<int>>& points){
    if(points.size()<=2) return points.size();
    int res=0;
    int n=points.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1 = points[i][1];
            int y2 = points[j][1];    
            // double slope = double(y2 - y1)/double(x2 - x1);
            int total=2;
            for(int k=0;k<n && k!=i && k!=j;k++){              
                int x = points[k][0];
                int y = points[k][1];
                // third point
                // double(y - y1)/double(x1 - x1)
                if((y2 - y1)*(x - x1) == (x2 - x1)*(y - y1))
                    total++;
            }
            res = max(res, total);
         }
     }
    return res;
}*/

//optimised approach
int gcd(int val1,int val2){
    if(val1==0) return val2;
    if(val2==0) return val1;
    int m1=max(val1,val2);
    int m2=min(val1,val2);
    if(m1%m2==0)    
        return m2;
    return gcd(m1%m2, m2);
}
void standardise(int &n, int &d){
    if(n==0)  d=1;
    if(d==0)  n=1;
    if( (n<0 && d<0)|| d<0){
        n*=-1;
        d*=-1;
    }
}
int maxPoints(vector<vector<int>>& points) {
    if(points.size()==0)
        return 0;
    int ans=1;
    map<pair<int,int>,int>m;
    for(int i=0;i<points.size();i++){
        int olp=0, maxm=0;
        for(int j=i+1;j<points.size();j++){
            if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                olp++;
            else{
                int xdiff=points[j][0]-points[i][0];
                int ydiff=points[j][1]-points[j][1];
                int g=gcd(abs(xdiff),abs(ydiff));
                int f=xdiff/g, s=ydiff/g;
                standardise(f,s);
                if(m.find({f,s})!=m.end())
                    m[{f,s}]++;
                else
                    m[{f,s}]=1;
                maxm=max(maxm,m[{f,s}]);
            }
        }
        ans=max(ans,1+olp+maxm);
        m.clear();
    }
    return ans;
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>>points(n,vector<int>(2));
	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			cin>>points[i][j];
	int ans=maxPoints(points);
	cout<<ans;		
}

