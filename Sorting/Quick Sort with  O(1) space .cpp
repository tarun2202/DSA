#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&a , int low , int high){
	int i = low + 1 ;
	int j = high;
	int pivot = a[low];
	while( i <= j){
		if(a[i] <= pivot)
			i++;
		else if(a[j] > pivot)
			j--;
		else
			swap(a[i] , a[j]);
	}
	swap(a[j] ,  a[low]);
	return j ;	//returning the index of partition point
}
void QS(vector<int>&a , int low , int high){
	if( low < high){
		int p = partition(a , low , high);
		QS(a , low , p - 1);
		QS( a , p + 1 , high);
	}
}
int main(){
	int n ;
	cin >> n ;
	vector<int>a(n);
	int i ;
	for( i = 0 ; i < n ; i++)
	cin >> a[i];
	QS(a, 0 , n - 1);
	for( i =  0 ; i < n ; i++)
		cout << a[i] << " ";
}
