/*	Job Sequencing Problem
	Given a set of N jobs where each jobi has a deadline and profit associated with it.
	Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit 
	associated with job if and only if the job is completed by its deadline.
	Find the number of jobs done and the maximum profit.
	Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
		Input:	N = 4   Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
		Output: 2 60
		Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
	
	time complexity: O(nlogn) +O(n*m)
	space complexity: O(m) 	
*/

class Solution 
{
    public:
    static bool mycmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,mycmp);
        int maxDeadline=0;
        for(int i=0;i<n;i++)
            maxDeadline=max(maxDeadline,arr[i].dead);
        
        bool vacant[maxDeadline]={false};
        int maxprofit=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(vacant[j]==false){
                    vacant[j]=true;
                    maxprofit+=arr[i].profit;
                    count+=1;
                    break;
                }
            }
        }
        vector<int> v;
        v.push_back(count);
        v.push_back(maxprofit);
        return v;
    }  
};
