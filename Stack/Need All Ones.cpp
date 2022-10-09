/*    Need All Ones
    given a boolean matrix of size MxN which contains only 0s and 1s. Find the max. area of rectangle whose-
    1) all cells conatins 1
    2) Base must be in last row.
    
        input:     3 3
                1 0 0
                0 1 1
                1 1 1
        output: 4
    time complexity : O(M*N) 
    space complexity: O(N)            
*/

#include<bits/stdc++.h>
using namespace std;
int allOnesRectangle(int m, int n, vector<vector<int>> &mat){
    int height[n], count, ones;
    //finding the count of consecutive ones in each col, then it in height vector.
    for(int i=0;i<n;i++){ //fixing columns
        height[i]=0;
        ones=0;
        count=0;
        for(int j=m-1;j>=0;j--){
            if(mat[j][i]==0){
                count=0;
                break;
            }
            else
                count++;
            ones=max(ones, count);
        }
        height[i]=ones;
    }
    stack<int>st;
    //m: size of height(height of histogram) vector
    vector<int>NSE(n,n),PSE(n,-1);
    //finding NSE[]
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && height[i]<height[st.top()]){
            NSE[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    //finding PSE[]
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && height[i]<height[st.top()]){
            PSE[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }    
    //finding max area of the rectangle fromed from histograms
    int maxArea=INT_MIN;
    for(int i=0;i<n;i++)
        maxArea=max(maxArea, height[i]*(NSE[i]-PSE[i]-1));
     return maxArea;       
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    int ans=allOnesRectangle(m,n,mat);
    cout<<ans;        
}

