class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        int start = 0;
        int end = n - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // Make mid even
            if (mid % 2 == 1)
                mid--;

            if (arr[mid] == arr[mid + 1]) {
                // Pair is complete, single is on the right
                start = mid + 2;
            }
            else {
                // Pair is broken, single is at mid or left
                end = mid;
            }
        }

        return arr[start];
    }
};