#include<bits/stdc++.h>
using namespace std;

//returns the count of elements in Union of two arrays
/*int findUnion(int a[], int m, int b[], int n){
	vector<int>ans;
	int i;
	for(i=0;i<m;i++)
		ans.push_back(a[i]);
	for(int j=0;j<n;j++)
		ans.push_back(b[j]);
	sort(ans.begin(),ans.end());
	int duplicate=0;
	for(int i=0;i<ans.size()-1;i++)
		if(ans[i]==ans[i+1])
			duplicate++;
	return ans.size()-duplicate;					
}*/

vector<int> findUnion(int arr1[], int n,  int arr2[], int m) {
    vector < int > v;
    v.push_back(min(arr1[0], arr2[0]));
    int i = 0;
    int j = 0;
    int k = 1;
    while (i < n and j < m) {
        if (arr1[i] < arr2[j]) {
            if (v[k - 1] != arr1[i]) {
                v.push_back(arr1[i]);
                k++;
            }
            i++;
        } 
		else if (arr1[i] == arr2[j]) {
            if (v[k - 1] != arr1[i]) {
                v.push_back(arr1[i]);
                k++;
            }
            i++;
            j++;
        } 
		else {
            if (v[k - 1] != arr2[j]) {
                v.push_back(arr2[j++]);
                k++;
            }
        }
    }
    while (i < n) {
        if (v[k - 1] != arr1[i]) {
            v.push_back(arr1[i++]);
            k++;
        }
    }
    while (j < m) {
        if (v[k - 1] != arr2[j]) {
            v.push_back(arr2[j++]);
            k++;
        }
    }
    return v;
}

int main(){
	int m,n;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++)
		cin>>a[i];
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	//int ans=findUnion(a,m,b,n);
	//cout<<ans;
	vector<int>ans = findUnion(a,m,b,n);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";		
}
