class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        int dip = n - 1;

        if (n == 1) {
            if (arr[0] == x)
                return 0;
            else
                return -1;
        }

        for (int i = 0; i < n - 1; i++) { // Finding the dip
            if (arr[i] > arr[i + 1]) {
                dip = i;
                break;
            } else {
                continue;
            }
        }

        int start = 0;
        int end = dip;

        while (start <= end) { // finding x in first half
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        start= dip+1;
        end= n-1;

        while (start <= end) { // finding x in second half
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }


        return -1;




    }
};