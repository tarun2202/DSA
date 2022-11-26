/*	Minimum Platforms
	Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms
	required for the railway station so that no train is kept waiting.
	Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can 
	never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
	At any given instance of time, same platform can not be used for both departure of a train and arrival of another 
	train. In such cases, we need different platforms.
		Input: n = 6 
				arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
				dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
		Output: 3
	
	naive approach--> TC: O(n^2)	SC: O(1)	: by finding the overlap intersection 
	better approach--> O(nlogn)		SC: O(n)
	optimised approach--> O(nlogn)	SC: O(1)	
*/

// better approach:  
/*class Solution{
    public:
    //Function to sort vector elements first according to time and if time is
    //same for two events, then arrival comes first followed by departure.
    static bool customsort(const pair<int,char> &p1,const pair<int,char> &p2)
    {
        if(p1.first == p2.first) 
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
    
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int,char>> order;
        
        //inserting all the values of time(arrival and departure)
        //in the vector of pairs.
        for (int i = 0; i < n; i++) {
    
            //if the time is of arrival then we keep second value
            //of pair as 'a' else 'd'.
            order.push_back({arr[i], 'a'});
            order.push_back({dep[i], 'd'});
        }
    
        //using custom sort vector, first according to time and if time is
        //same for two events, then arrival comes first followed by departure.
        sort(order.begin(),order.end(),customsort);
    
        int result = 0;
        int plat_needed = 0;
    
        for (int i=0;i<order.size();i++){
            //if the second value of vector element is 'a' which stands
            //for arrival then we add 1 to platform needed else we 
            //subtract 1 from platform needed.
            if (order[i].second == 'a')
                plat_needed++;
            else
                plat_needed--;
            
            //we keep updating the value of result.
            if (plat_needed>result)
                result = plat_needed;
        }
        //returning the minimum number of platforms required.
        return result;
    }
};*/

//optimised approach:
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
        sort(arr,arr+n);
        sort(dep,dep+n);
 
        int ans=0;
        int count=0;
        int i=0,j=0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]) //one more platform needed
            {
                count++;
                i++;
            }
            else //one platform can be reduced
            {
                count--;
                j++;
            }
            ans=max(ans,count); //updating the value with the current maximum
        }
        return ans;
    }
};



