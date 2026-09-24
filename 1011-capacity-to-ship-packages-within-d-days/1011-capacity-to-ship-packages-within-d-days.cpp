class Solution {
public:
    // Checks: "if every ship trip carries at most ship_wt weight,
    // can we finish shipping all packages within dayLimit days?"
    bool check_days(vector<int>& arr, int ship_wt, int dayLimit){
        
        int i = 0;              // index of the current package we're trying to load
        int item_wt = 0;        // total weight loaded on the CURRENT day so far
        int trip_count = 1;     // we start on day 1 the moment loading begins
                                 // (if nothing ever overflows, we still used 1 day)
        int n = arr.size();

        while(i < n){

            // Case 1: today's package fits within today's remaining capacity
            if(item_wt + arr[i] <= ship_wt){
                item_wt += arr[i];   // load it onto today's trip
                i++;                 // ONLY move to the next package because
                                      // this one has successfully been shipped.
                                      // This is the fix: i advances if and only
                                      // if arr[i] was actually placed on a ship.
            }

            // Case 2: today's package does NOT fit anymore — today's trip is full
            else{
                trip_count++;        // close today's trip, open a new day
                item_wt = 0;         // new day starts with an empty ship

                // If we've already used more days than allowed, this capacity
                // (ship_wt) is too small — fail fast, no point continuing
                if(trip_count > dayLimit) return false;

                // IMPORTANT: we do NOT increment i here.
                // arr[i] was never actually shipped — it just didn't fit
                // in TODAY's trip. By leaving i unchanged, the while loop
                // will re-check arr[i] on the next pass, now against a
                // freshly emptied ship (item_wt = 0). This is what carries
                // the "overflowing" package forward into the next day
                // instead of losing it.
            }
        }

        // We successfully placed every package within the day limit
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Binary search is done over the CAPACITY of the ship (the answer),
        // not over the array itself.

        // Lower bound: the ship must be able to carry at least the heaviest
        // single package, otherwise that package can never be shipped at all.
        int start = *max_element(weights.begin(), weights.end());

        // Upper bound: if the ship can carry the sum of everything,
        // we can ship all packages in a single day (trivially valid).
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = start;   // fallback answer, will be overwritten by the search

        // Standard "find the minimum valid value" binary search template
        while (start <= end) {

            int mid = start + (end - start) / 2;   // candidate ship capacity
                                                     // (written this way to avoid
                                                     // integer overflow vs (start+end)/2)

            // Check if this capacity lets us ship everything within 'days'
            if (check_days(weights, mid, days)) {
                ans = mid;        // this capacity WORKS — record it as our best answer so far
                end = mid - 1;    // but try to find an even SMALLER capacity that still works
            }
            else {
                start = mid + 1;  // this capacity is too small — we need more room,
                                   // so search the upper half instead
            }
        }

        return ans;   // smallest capacity that still meets the day limit
    }
};