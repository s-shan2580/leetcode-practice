class Solution {
public:
    bool check_days(vector<int>& arr, int ship_wt, int dayLimit){

        int i = 0;
        int item_wt = 0;
        int trip_count = 1;
        int n = arr.size();

        while(i<n){
            if(item_wt + arr[i] <= ship_wt){
                item_wt += arr[i]; 
                i++;
            }
            else{
                item_wt = 0;
                trip_count++;
                
                if(trip_count > dayLimit) return false;
            }
        }

        return (trip_count <= dayLimit);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = start;

         while (start <= end) {

            int mid = start + (end - start) / 2;

            if (check_days(weights, mid, days)) {
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