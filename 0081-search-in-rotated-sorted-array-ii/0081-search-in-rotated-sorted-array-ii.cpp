class Solution {
public:
    bool search(vector<int>& arr, int x) {
        int n = arr.size();

        int start = 0;
        int end = n - 1;

        while (start <= end) {

    int mid = start + (end - start) / 2;

    if (arr[mid] == x)
        return true;

    if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
        start++;
        end--;
    }

    else if (arr[mid] <= arr[end]) {
        // Right half is sorted

        if (arr[mid] <= x && x <= arr[end])
            start = mid + 1;
        else
            end = mid - 1;
    }

    else {
        // Left half is sorted

        if (arr[start] <= x && x <= arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
}

        return false;
    }
};