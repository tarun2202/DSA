/*	264. Ugly Number II
	An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
	Given an integer n, return the nth ugly number.
		Input: n = 10
		Output: 12
		Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
		
	time complexity: O(n+logn)	
*/

class Solution {
public:
    int nthUglyNumber(int n) {      
        // method 3: using min-heap--> TC: O(n+logn)
        if(n==1)
            return 1;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        pq.push(1);
        unordered_map<long long, bool>umap;
        umap[1]=true;
        long long ans;
        vector<int>primes{2,3,5};
        while(n--){
            ans=pq.top();
            pq.pop();
            for(int i=0;i<3;i++){
                if(umap.find(primes[i]*ans)==umap.end()){
                    pq.push(primes[i]*ans);
                    umap[ans*primes[i]]=true;
                }
            }
        }
        return ans;
    }
};
