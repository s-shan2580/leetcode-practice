class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        int last = nums[n - 1];
        int ans = last;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= last) {
                ans = nums[mid];
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};