class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=val) nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(),nums.begin()+n);

        return nums.size();
    }
};