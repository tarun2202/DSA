/*	Circular tour
	Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
	1. The amount of petrol that every petrol pump has.
	2. Distance from that petrol pump to the next petrol pump.
	Find a starting point where the truck can start to get through the complete circle without exhausting its petrol 
	in between.
		Input: N = 5  Petrol = [1 2 3 4 5]  Distance = [3 4 5 1 2]
		Output: 3
	
	naive approach    --> TC: O(n^2)	SC: O(1)
	optimised approach--> TC: O(n)	 	SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//brute force 
/*int isCircularTour(vector<int> &petrol, vector<int> &distance){
	int n = petrol.size();
	for(int i=0; i<n; i++){
		int gasRequired = petrol[i]-distance[i];
		if(gasRequired<0)
			continue;
		int nextStation=(i+1)%n;
		int currPetrol = gasRequired + petrol[nextStation];
		while(nextStation!=i){
			if(currPetrol<distance[nextStation])
				break;
			int prevDistance=distance[nextStation];
			nextStation = (nextStation+1)%n;
			currPetrol = currPetrol-prevDistance+petrol[nextStation]; 	
		}	
		if(i==nextStation)
			return nextStation;
	}
	return -1;
}*/

// optimised approach-
int isCircularTour(vector<int> &petrol, vector<int> &distance){
	int n = petrol.size();
	int remainingFuel=0, netFuel=0, startingStation=0;
	for(int i=0;i<n;i++){
		remainingFuel+=petrol[i]-distance[i];
		if(remainingFuel<0){
			startingStation=i+1;
			remainingFuel=0;
		}
		netFuel+=petrol[i]-distance[i];
	}	
	return (netFuel<0) ? -1: startingStation;
}

int main(){
	int n;
	cin>>n;
	vector<int>petrol(n);
	vector<int>distance(n);
	for(int i=0;i<n;i++)
		cin>>petrol[i];
	for(int i=0;i<n;i++)
		cin>>distance[i];
	int ans=isCircularTour(petrol, distance);
	cout<<ans;		
}
