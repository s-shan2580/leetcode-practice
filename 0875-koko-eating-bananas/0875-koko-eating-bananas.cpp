class Solution {
public:

    long long calcTotal_time(vector<int>& piles, long long hour_rate) {

        long long totalhrs = 0;

        for (int pile : piles) {
            totalhrs += ((long long)pile + hour_rate - 1) / hour_rate;
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            long long totalHrs = calcTotal_time(piles, mid);

            if (totalHrs <= h) {
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