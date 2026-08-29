class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int len = 1;
        int maxlen = 1;

        if (n == 0) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        int i = 1;
        while (i < n) {
            if (arr[i] - arr[i - 1] == 1) {
                len++;
                if (len >= maxlen)
                    maxlen = len;
            } else if (arr[i] == arr[i - 1]) {
                i++;
                continue;
            } else {
                len = 1;
            }
            i++;
        }

        return maxlen;
    }
};