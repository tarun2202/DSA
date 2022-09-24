#include <bits/stdc++.h>
using namespace std;
int partion(vector<int> &arr, int low, int high){
	vector<int> lesser;
	vector<int> greater;
	int pivot = arr[low];
	int i, j;
	for (i = low + 1; i <= high; i++){
		if (arr[i] <= pivot)
			lesser.push_back(arr[i]);
		else
			greater.push_back(arr[i]);
	}
	i = 0;
	int k = low;
	while (i < lesser.size())
		arr[k++] = lesser[i++];
	int p = k;
	arr[k] = pivot;
	k++;
	j = 0;
	while (j < greater.size())
		arr[k++] = greater[j++];
	return p;
}
void QS(vector<int> &arr, int low, int high){
	if (low < high){
		int p = partion(arr, low, high);
		QS(arr, low, p - 1);
		QS(arr, p + 1, high);
	}
}
int main()
{
	int n;
	cin >> n;
	int i;
	vector<int> arr(n);
	for (i = 0; i < n; i++)
		cin >> arr[i];
	QS(arr, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
}
