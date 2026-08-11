class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int n = arr.size();
        double windowSum = 0;
        double maxSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        maxSum = windowSum;

        for (int i = k; i < n; i++) {
            windowSum = (windowSum + arr[i] - arr[i - k]);
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};