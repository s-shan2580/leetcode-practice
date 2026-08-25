class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0; // Tracks next positive element
        int j = 0; // Tracks next negative element
        int k = 0;
        vector<int> res;
        
        while (k < n) {
            if (k % 2 == 0) {
                while (i < n && arr[i] < 0) i++;
                res.push_back(arr[i]);
                i++; // Advance past the matched positive
            } else {
                while (j < n && arr[j] > 0) j++;
                res.push_back(arr[j]);
                j++; // Advance past the matched negative
            }
            k++; // Advance the main counter
        }

        return res;
    }
};