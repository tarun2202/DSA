/*	N meetings in one room
	There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is 
	start time of meeting i and end[i] is finish time of meeting i.
	What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can 
	be held in the meeting room at a particular time?
	Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
	
		Input: N = 6  start[] = {1,3,0,5,8,5}  end[] =  {2,4,6,7,9,9}
		Output: 4
		Explanation: Maximum four meetings can be held with given start and end timings.
					 The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
	
	time complexity: O(nlogn)
	space complexity: O(n)				 
*/

class Solution
{
    public:
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int m=v[0].second;
        int ans = 1;
        for(int i=1;i<n;i++){
            if(v[i].first>m){
                ans++;
                m=v[i].second;
            }
        }
        return ans;
    }
};
