class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long maxsum = arr[0];
        long long sum = 0;
        long long minPrefixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // MAX SUBARRAY ENDING AT i IS CURRENT PREFIX SUM MINUS THE SMALLEST PREFIX SUM SEEN BEFORE
            if (sum - minPrefixSum > maxsum) {
                maxsum = sum - minPrefixSum;
            }
            
            // UPDATE MINIMUM PREFIX SUM
            if (sum < minPrefixSum) {
                minPrefixSum = sum;
            }
        }

        return maxsum;
    }
};
