class Solution {
public:
    // Checks whether all packages can be shipped within dayLimit days
    bool check_days(vector<int>& arr, int ship_wt, int dayLimit) {

        int i = 0;
        int item_wt = 0;
        int trip_count = 1;
        int n = arr.size();

        while(i < n) {

            // Current package fits in today's capacity
            if(item_wt + arr[i] <= ship_wt) {
                item_wt += arr[i];
                i++;
            }

            // Package doesn't fit: start a new day
            else {
                trip_count++;
                item_wt = 0;

                if(trip_count > dayLimit)
                    return false;

                // Don't increment i: package is still unshipped
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum and maximum possible capacities
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = start;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(check_days(weights, mid, days)) {
                ans = mid;       // Valid capacity, try smaller
                end = mid - 1;
            }
            else {
                start = mid + 1; // Invalid capacity, increase it
            }
        }

        return ans;
    }
};