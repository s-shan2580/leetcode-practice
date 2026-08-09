class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int x: nums){
            s.insert(x);
        }
        nums.clear();
        for(int x: s){
           nums.push_back(x);
        }
        return nums.size();

    }
};