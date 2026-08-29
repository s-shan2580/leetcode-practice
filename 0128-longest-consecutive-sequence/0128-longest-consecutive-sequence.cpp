class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }

        unordered_set<int> st(arr.begin(), arr.end());
        int maxlen = 1; // OR 0, BUT 1 WORKS SINCE WE HANDLED THE EMPTY CASE

        for (int num : st) {
            // ONLY START COUNTING IF IT IS THE FIRST NUMBER IN A SEQUENCE
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int len = 1;

                // COUNT UPWARDS AS LONG AS THE NEXT NUMBER EXISTS
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    len++;
                }

                if (len >= maxlen) {
                    maxlen = len;
                }
            }
        }

        return maxlen;
    }
};