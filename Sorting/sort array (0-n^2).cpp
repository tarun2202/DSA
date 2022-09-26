/*	Efficiently sorting numbers in range from 0 to n^2 - 1
	Given an array of numbers of size N. It is also given that the array elements are in range from 0 to N2 – 1. 
	Sort the given array in linear time.
			Input: arr[] = {40, 12, 45, 32, 33, 1, 22}
			Output: {1, 12, 22, 32, 33, 40, 45}
*/

#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &a){
	int i;
	int n = a.size();
	int maxi = INT_MIN;
	for (i = 0; i < n; i++)
		maxi = max(maxi, a[i]);
	return maxi;
}
void solve(vector<int> &a){
	int n = a.size();
	vector<int> ans(n, 0);
	int factor = 1;
	int base = n;
	int maxi = find(a);
	while (maxi != 0){
		vector<int> fre(n, 0);
		for (int i = 0; i < a.size(); i++){
			int temp = a[i];
			temp = temp / factor;
			int digit = temp % base;
			fre[digit]++;
		}
		for (int i = 1; i < n; i++)
			fre[i] += fre[i - 1];
		for (int i = a.size() - 1; i >= 0; i--){
			int temp = a[i];
			temp = temp / factor;
			int digit = temp % base;
			int index = fre[digit];
			ans[index - 1] = a[i];
			fre[digit]--;
		}
		for (int i = 0; i < n; i++)
			a[i] = ans[i];
		factor *= base;
		maxi = maxi / factor;
	}
	for (int i = 0; i < n; i++)
		a[i] = ans[i];
}
int main(){
	int n;
	cin >> n;
	int i;
	vector<int> a(n);
	for (i = 0; i < n; i++)
		cin >> a[i];
	solve(a);
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
}
