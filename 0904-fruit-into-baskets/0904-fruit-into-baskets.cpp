class Solution {
public:

    // this qn is nothing but finding the max length of a contiguous subarray that has at most only 2 diff 
    // elements and those 2 diff elements can be as many times as one can.
    int totalFruit(vector<int>& arr) {

        int l = 0;
        int maxlen = 0;
        unordered_map<int, int> basket; 
        // this will store diff fruit types and their count, its main job is that from this basket
        // we will check and ensure that its size remains <=2 only i.e, only 2 varieties of fruits acceptable
        // if at any moment its size increases then we will shrink it from left side,
        // the baskets elements would be that of the window sliding over the array.

        for(int r=0; r<arr.size(); r++){

            // sabse pehle jo element aaya hai newly window me usko basket me dalo alongwith its frequency
            basket[arr[r]]++; 

            // now if basket size increased from 2, means 2 se jyada variety hai fruits ki curr window mein
            // try to eliminate from left
            while(basket.size()>2){

                basket[arr[l]]--;   //decrememnt the count of fruit of whatever type from left

                if(basket[arr[l]] == 0){    //agar bychance wo type ka fruit 0 ho gya to usko puta hi nikal do
                    basket.erase(arr[l]);
                }

                l++;  //agar abhi bhi basket size nahi ghata ho (wo upr wala if nhi chala),to next ele try maro

            }

            maxlen = max(maxlen, r-l+1);
        }

        return maxlen;

    }
};