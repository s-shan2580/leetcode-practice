class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();

        int start = 0;
        int end = n - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == x) {
                return mid;
            }

            // Left half is sorted
            else if (arr[start] <= arr[mid]) {

                if (arr[start] <= x && x < arr[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (arr[mid] < x && x <= arr[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};