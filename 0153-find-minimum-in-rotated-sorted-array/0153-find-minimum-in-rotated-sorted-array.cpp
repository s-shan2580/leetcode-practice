class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        int last = nums[n - 1];

        while (start < end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] <= last) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }

        return nums[start];
    }
};