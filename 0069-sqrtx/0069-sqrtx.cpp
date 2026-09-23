class Solution {
public:
    int mySqrt(int x) {
        long long start = 1;
        long long end = x/2;
        int ans = 1;

        if(x==1 || x==0) return x;

        while(start <= end){
            long long mid = start + (end-start)/2;

            if(mid*mid <= x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
};