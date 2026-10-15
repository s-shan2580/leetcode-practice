class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            stk.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            if (!stk.empty()) {
                res[i] = stk.top();
            }
            stk.push(nums[i]);
        }

        return res;
    }
};