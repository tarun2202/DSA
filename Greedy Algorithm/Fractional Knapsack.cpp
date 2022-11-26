/*	Fractional Knapsack
	Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum 
	total value in the knapsack.
	Note: Unlike 0/1 knapsack, you are allowed to break the item.
		Input:	N = 3, W = 50
				values[] = {60,100,120}
				weight[] = {10,20,30}
		Output:	240.00
	
	time complexity: O(nlogn)
	space complexity: O(1)	
*/

class Solution{
    public:
    //comparison function to sort items according to value/weight ratio.
    static bool cmp(Item a, Item b){
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        //sorting items on basis of value/weight ratio.
        sort(arr, arr + n, cmp);
        //taking variable for current weight in knapsack.
        int curWeight = 0;
        double finalvalue = 0.0;
        //iterating over all the items.
        for (int i = 0; i < n; i++){
            //if currweight + item's weight is less than or equal to W,
            //then we add the item's value to final value.
            if (curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            //else we take the fraction of the that item's value 
            //based on the remaining weight in knapsack.
            else{
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double) remain / arr[i].weight);
                break;
            }
        }
        //returning final value.
        return finalvalue;
    }
};
