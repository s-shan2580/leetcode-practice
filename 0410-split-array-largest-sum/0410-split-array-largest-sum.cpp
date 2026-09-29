class Solution {
public:

    // Returns the minimum number of subarrays needed so that
    // no subarray has sum greater than max_sum.
    // Elements must be divided in contiguous order.
    int countSubarrays(vector<int>& nums, long long max_sum) {

        int n = nums.size();

        int subarrays_used = 1;       // start with the first subarray
        long long current_sum = 0;    // sum of current subarray

        for (int i = 0; i < n; i++) {

            // Can current subarray take this element?
            if (current_sum + nums[i] <= max_sum) {
                current_sum += nums[i];
            }
            else {
                // No, so start a new subarray
                subarrays_used++;
                current_sum = nums[i];
            }
        }

        return subarrays_used;
    }


    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        // Search space for the answer:
        //
        // Lower bound = largest element
        // because every element must belong to some subarray.
        long long low = *max_element(nums.begin(), nums.end());

        // Upper bound = sum of all elements
        // when everything is put into one subarray.
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        long long answer = high;

        // Binary search on the answer
        while (low <= high) {

            long long mid = low + (high - low) / 2;

            // Number of subarrays required if
            // maximum allowed sum is mid.
            int subarrays_needed = countSubarrays(nums, mid);

            if (subarrays_needed > k) {

                // We need more than k subarrays.
                // Therefore mid is too small.
                low = mid + 1;
            }
            else {

                // k or fewer subarrays are enough.
                // mid is feasible, so try a smaller value.
                answer = mid;
                high = mid - 1;
            }
        }

        return answer;
    }
};