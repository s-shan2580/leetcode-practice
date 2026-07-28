class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int need=target-a;
            if(mp.find(need)!=mp.end()){
                return {mp[need], i};
            }
            mp[a]=i;
        }

        return {-1,-1};
    }
};