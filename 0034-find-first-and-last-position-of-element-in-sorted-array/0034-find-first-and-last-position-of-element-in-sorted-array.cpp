class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int first = -1;
        int last = -1;
        int n = arr.size();

        int start = 0;
        int end = n - 1;

        if (n == 0) {
            return {-1, -1};
        }

        while (start <= end) { // finding first occurance
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                first = mid;
                end = mid - 1;
            } 
            else if(arr[mid] > x) {
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

         start = 0;
         end = n - 1;

        while (start <= end) { // finding last occurance
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                last = mid;
                start = mid + 1;
            }
            else if(arr[mid] > x) {
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return {first , last};
    }
};