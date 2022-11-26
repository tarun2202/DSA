/*	295. Find Median from Data Stream
	Implement the MedianFinder class:
	MedianFinder() initializes the MedianFinder object.
	void addNum(int num) adds the integer num from the data stream to the data structure.
	double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
		Input: ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
				[[], [1], [2], [], [3], []]
		Output: [null, null, null, 1.5, null, 2.0]

	time complexity: O(logn)
	space complexity: O(
*/

class MedianFinder {
public:
    //for the first n/2 elements: pick max element to find the median
    priority_queue<int>maxHeap; 
    //for 2nd half of n/2 elements: pick min element to find the median
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    double currMedian;
    void updateMedian(){
        if(maxHeap.size()==minHeap.size())
            currMedian=(maxHeap.top()+minHeap.top())/2.0;
        else if(maxHeap.size()>minHeap.size())
            currMedian=maxHeap.top();
        else
            currMedian=minHeap.top();
    }
    void addToMinHeap(int num){
        if(maxHeap.size()>=minHeap.size())
            minHeap.push(num);
        else{
            int x = minHeap.top();
            minHeap.pop();
            maxHeap.push(x);
            minHeap.push(num);
        }
    }
    void addToMaxHeap(int num){
        if(minHeap.size()>=maxHeap.size())
            maxHeap.push(num);
        else{
            int x=maxHeap.top();
            maxHeap.pop();
            minHeap.push(x);
            maxHeap.push(num);
        }
    }
    MedianFinder() {
        currMedian=0.0;
    }
    
    void addNum(int num) {
        if(num<=currMedian)
            addToMaxHeap(num);
        else 
            addToMinHeap(num);
        updateMedian();
    }
    
    double findMedian() {
        return currMedian;
    }
};
