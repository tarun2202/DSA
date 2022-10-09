/*	84. Largest Rectangle in Histogram
	Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
	return the area of the largest rectangle in the histogram.
		Input: heights = [2,1,5,6,2,3]
		Output: 10
	
	naive approach--> 	  TC: O(n^2)	SC: O(1)
	optimised approach--> TC: O(n)		SC: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;

//optimised approach
int largestArea(vector<int> &height, int n){
	stack<int>st;
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

//naive approach
/*int largestArea(vector<int> &height, int n){
	int maxArea=0;
	int minHeight=INT_MAX;
	for(int i=0;i<n;i++){
		minHeight=height[i];
		for(int j=i;j<n;j++){
			minHeight=min(minHeight,height[j]);
			maxArea=max(maxArea,minHeight*(j-i+1));
		}
	}
	return maxArea;
}*/

int main(){
	int n;
	cin>>n;
	vector<int>height(n);
	for(int i=0;i<n;i++)
		cin>>height[i];
	int maxArea=largestArea(height, n);
	cout<<maxArea;	
}
