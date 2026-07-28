class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid element is greater than the rightmost element,
            // the minimum lies in the right half
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } 
            // Otherwise, the minimum lies in the left half (including mid)
            else {
                end = mid;
            }
        }

        // start == end pointing to the minimum element
        return nums[start];
    }
};