class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int oddcount = 0;
        mp[0] = 1;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0)
                oddcount++;

            if (mp.find(oddcount - k) != mp.end()) {
                ans += mp[oddcount - k];
            }

            mp[oddcount]++;
        }
        return ans;
    }
};