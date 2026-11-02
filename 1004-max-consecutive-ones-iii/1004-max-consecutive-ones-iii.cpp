class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0;
        int zeroes = 0;
        int maxlen = 0;

        while(r < arr.size()){
            if(arr[r] == 0) zeroes++;

            while(zeroes > k){
                if(arr[l]==0) zeroes--;
                l++;
            }

            maxlen = max(maxlen, r-l+1);

            r++;
        }

        return maxlen;
    }
};