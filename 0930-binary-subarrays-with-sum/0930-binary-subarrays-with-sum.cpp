class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 1;
        int sum = 0;

        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            
            if(mp.find(sum - goal) != mp.end()){
                count += mp[sum - goal];
            }
            
            mp[sum]++;
        }

        return count;
    }
};