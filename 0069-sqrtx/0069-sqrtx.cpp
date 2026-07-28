class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;   // handle 0 and 1 directly
        
        long long start = 1, end = x/2, ans = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long sq = mid * mid;
            
            if (sq == x) return mid;
            else if (sq < x) {
                ans = mid;      // store candidate
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};