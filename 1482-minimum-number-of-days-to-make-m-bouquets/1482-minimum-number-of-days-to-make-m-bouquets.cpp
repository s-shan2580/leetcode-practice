class Solution {
public:
    int checkadj(vector<int>& arr, int days, int m, int k){
        int streak = 0, count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= days){
                streak++;
                if(streak == k){
                    count++;
                    streak = 0;
                }
            } else {
                streak = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers = (long long)m * k;
        int n = bloomDay.size();
        if (totalflowers > n) return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(checkadj(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};