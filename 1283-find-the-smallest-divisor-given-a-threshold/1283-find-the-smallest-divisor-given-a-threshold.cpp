class Solution {
public:
    bool check_sum(vector<int>& arr, int divisor, int x) {

        long long sum = 0;

        for (int item : arr) {
            sum += ((long long)item + divisor - 1) / divisor;
            if (sum > x)
                return false;
        }

        return (sum <= x);
    }
    int smallestDivisor(vector<int>& arr, int x) {

        int start = 1;
        int end = *max_element(arr.begin(), arr.end());
        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (check_sum(arr, mid, x)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};